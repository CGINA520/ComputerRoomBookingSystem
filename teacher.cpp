#include "teacher.h"

//�޲ι���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_Empid = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼!" << endl;
	cout << "\t\t_____________________________________\n";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           1.�� �� �� �� Ԥ Լ     |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           2.�� �� Ԥ Լ           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           0.ע �� �� ¼           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t_____________________________________\n";
	cout << "��ѡ����Ĳ���" << endl;
}

//�鿴�����˵�ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << " ";
		cout << "ԤԼ���ڣ� ��" << of.m_OrderData[i]["date"];
		cout << "  ԤԼʱ�Σ� " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << "  ѧ�ţ� " << of.m_OrderData[i]["stuId"];
		cout << "  ������ " << of.m_OrderData[i]["stuName"];
		cout << "  �����ţ� " << of.m_OrderData[i]["roomId"];
		//״̬˵��
		//1 �����   2 ��ԤԼ   -1 ԤԼʧ��  0 ȡ��ԤԼ
		string status = "  ״̬�� ";
		if (of.m_OrderData[i]["status"] == "1") status += "�����";
		else if (of.m_OrderData[i]["status"] == "2") status += "��ԤԼ";
		else if (of.m_OrderData[i]["status"] == "-1") status += "ԤԼʧ��";
		else status += "ԤԼȡ��";
		cout << status << endl;
	}
	system("pause");
	system("cls");
	return;
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	vector<int> v;
	cout << "����е�ԤԼ��¼���£�" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		//�ж�ԤԼ״̬�Ƿ�Ϊ�����
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << " ";
			cout << "ԤԼ���ڣ� ��" << of.m_OrderData[i]["date"];
			cout << "  ԤԼʱ�Σ� " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  �����ţ� " << of.m_OrderData[i]["roomId"];
			string status = "  ״̬�� ";
			if (of.m_OrderData[i]["status"] == "1") status += "�����";
			cout << status << endl;
		}
	}

	int select = 0;
	int ret = 0;
	while (true)
	{
		cout << "������˵�ԤԼ��¼��0������" << endl;
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "��������˵Ľ��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1) of.m_OrderData[v[select - 1]]["status"] = "2";
				else if (ret == 2) of.m_OrderData[v[select - 1]]["status"] = "-1";
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}