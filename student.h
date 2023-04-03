#pragma once
#include "identity.h"
#include <vector>
#include <fstream>
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"

class Student:public Identity
{
public:
	//无参构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancleOrder();
	
	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom> vCom;
};
