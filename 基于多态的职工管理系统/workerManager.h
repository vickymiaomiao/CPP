#pragma once   //防止头文件重复包含
#include <iostream>   //包含输入输出流头文件
using namespace std;   //使用标准的命名空间
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager(); //构造函数

	void Show_Menu();  //展示菜单

	void exitSystem(); //退出程序

	//记录职工人数
	int m_EemNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	~WorkerManager();  //析构函数


};



