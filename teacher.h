#pragma once
#include "identity.h"
#include "orderFile.h"
#include <vector>

class Teacher:public Identity
{
public:
	//�޲ι���
	Teacher();

	//�вι���
	Teacher(int empid, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴�����˵�ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ����
	int m_Empid;

};
