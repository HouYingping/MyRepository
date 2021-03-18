#pragma once
#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
#include<fstream>
#include"speaker.h"
class SpeechManager {
public:
	SpeechManager();
	void show_Menu();
	void exitSystem();
	void createSpeaker();
	//初始化
	void initSpeech();
	//开始比赛
	void startspeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示得分
	void showScore();
	//记录得分
	void saveRecord();
	//读取记录
	void loadRecord();
	//展示记录
	void showRecord();
	//清空记录
	void clearRecord();
	~SpeechManager();
	
	//保存第一轮的选手编号
	vector<int> v1;
	//保存第一轮晋级的选手编号
	vector<int> v2;
	//胜出前3名选收编号容器
	vector<int> vVectory;
	//存放编号以及对应具体选手容器
	map<int, Speaker> m_Speaker;
	//比赛轮数
	int m_index;
	// 文件为空的标志
	bool fileIsEmpty;
	// 往届比赛记录
	map<int, vector<string>> m_Record;
};
