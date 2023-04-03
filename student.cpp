#include "student.h"

//�޲ι���
Student::Student()
{

}

//�вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼!" << endl;
	cout << "\t\t_____________________________________\n";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           1.�� �� Ԥ Լ           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           2.�� �� �� �� Ԥ Լ     |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           3.�� �� �� �� Ԥ Լ     |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           4.ȡ �� Ԥ Լ           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           0.ע �� �� ¼           |\n ";
	cout << "\t\t_____________________________________\n";
	cout << "��ѡ����Ĳ���" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	int date;    //ԤԼ����
	int interval;//ԤԼʱ��
	int room;    //ԤԼ������

	cout << "����ԤԼ����������һ������" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << "������ԤԼ������" << endl;
	cin >> date;
	while (true)
	{
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "ʱ�����,���������룡" << endl;
	}

	cout << "����ԤԼ��ʱ������:" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cout << "������ԤԼʱ��" << endl;
	cin >> interval;
	while (true)
	{
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "ʱ�δ�������������!" << endl;
	}

	cout << "������Ϣ���£�" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż�������������ǣ�" << vCom[i].m_MaxNum << endl;
	}
	cout << "������ԤԼ�Ļ�����" << endl;
	cin >> room;
	while (true)
	{
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�������������������룡" << endl;
	}

	cout << "ԤԼ�ɹ�����������У�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	
	ofs.close();
	system("pause");
	system("cls");

}

//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//string תΪ int
		//string ���� .c_str()תΪ const char*
		//����atoi (const char*)תΪ int
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			cout << "ԤԼ����:  ��" << of.m_OrderData[i]["date"];
			cout << "  ԤԼʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  �����ţ�" << of.m_OrderData[i]["roomId"];
			//״̬˵��
			//1 �����   2 ��ԤԼ   -1 ԤԼʧ��  0 ȡ��ԤԼ
			string status = "  ״̬�� ";
			if (of.m_OrderData[i]["status"] == "1") status += "�����";
			else if (of.m_OrderData[i]["status"] == "2") status += "��ԤԼ";
			else if (of.m_OrderData[i]["status"] == "-1") status += "ԤԼʧ��";
			else status += "ԤԼȡ��";
			cout << status << endl;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
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
		cout << "  ԤԼʱ��: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
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
	cout << endl;
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancleOrder()
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
	for (int i = 0; i < of.m_Size; i++)
	{
		//�ж��Ƿ�������
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//�ж��Ƿ������״̬����ԤԼ�ɹ�״̬
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << " ";
				cout << "ԤԼ����:  ��" << of.m_OrderData[i]["date"];
				cout << "  ԤԼʱ�Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "  �����ţ� " << of.m_OrderData[i]["roomId"];
				string status = "  ״̬: ";
				if (of.m_OrderData[i]["status"] == "1") status += "�����";
				else if (of.m_OrderData[i]["status"] == "2") status += "��ԤԼ";
				cout << status << endl;
			}
		}
	}

	while (true)
	{
		cout << "��ѡ��Ҫȡ����ԤԼ��¼��0������" << endl;
		int select = 0;
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0) break;
			else 
			{
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "ȡ��ԤԼ�ɹ�" << endl;
				break;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
	}

	system("pause");
	system("cls");
}
