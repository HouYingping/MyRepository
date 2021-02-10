#include"类模板.hpp"
void test() {
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
	for (int i = 0;i < 5;i++) {
		//arr1[i] = i;			//还没有解决
		arr1.push_back(i+1);
	}
	for (int j = 0;j < arr1.getSize();j++) {
		cout << "第" << j+1 << "个值是：" << arr1[j] << endl;
	}
}
int main() {
	test();
	system("pause");
	return 0;
}
