#pragma once
#include "identity.h"
#include "orderFile.h"
#include <vector>

class Teacher:public Identity
{
public:
	//无参构造
	Teacher();

	//有参构造
	Teacher(int empid, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有人的预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//职工号
	int m_Empid;

};
