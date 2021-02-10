#pragma
#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyArray {
public:
	//有参构造 参数 容量
	MyArray(int capacity) {
		cout << "MyArray有参构造函数" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr) {
		cout << "MyArray拷贝构造函数" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0;i < this->size;i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	// 防止浅拷贝，
	MyArray& operator=(const MyArray& arr) {
		cout << "MyArray的operator=构造函数" << endl;
		// 先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->size = 0;
			this->capacity = 0;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0;i < this->size;i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插
	void push_back(const T& val) {
		if (this->capacity == this->size) {
			cout << "数组已满，无法再插入元素" << endl;
			return;
		}
		else {
			this->pAddress[this->size] = val;
			this->size += 1;
		}
	}
	// 通过下标方式访问数组中的数据
	T& operator[](int index) {		// 可以作为左值存在，需要返回数据的引用	 a[0]=100;
		while (index<this->size || index==0)
		{
			if (index < 0) {
				index = this->capacity + index;
			}
			/*if (this->pAddress[index]) {
				cout << "看一下空值的时候是什么：" << pAddress[index] << endl;
			}*/
			return this->pAddress[index];
		}
		cout << "下标越界" << endl;
	}

	void pop_back() {
		if (this->size == 0) {
			cout << "数组已空，无法再进行删除操作" << endl;
			return;
		}
		else {
			this->size -= 1;
		}
	}

	~MyArray() {
		cout << "MyArray析构函数" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->size = 0;
			this->capacity = 0;
		}
	}
	int getSize() {
		return this->size;
	}
private:
	T * pAddress;		// 指针指向堆区开辟的真实数组
	int capacity = 0;
	int size = 0;
};
