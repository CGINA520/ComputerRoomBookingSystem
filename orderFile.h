#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>> m_OrderData;
};