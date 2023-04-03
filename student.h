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
	//�޲ι���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancleOrder();
	
	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};
