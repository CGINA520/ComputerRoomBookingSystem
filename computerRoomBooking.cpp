#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//�������Ա�Ӳ˵�����
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//���ù���Ա���Ӳ˵�
		manager->operMenu(); 

		//������ָ��ת��Ϊ����ָ���������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://����˺�
			man->addPerson();
		    break;
		case 2://�鿴�˺�
			man->showPerson();
			break;
		case 3://�鿴������Ϣ
			man->showComputer();
			break;
		case 4://���ԤԼ��¼
			man->clearFile();
			break;
		default://ע��
			delete manager;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//����ѧ�����˵��������
void studentMenu(Identity*& student)
{
	while (true)
	{
		//��ʾѧ���˵�
		student->operMenu();

		//������ָ��ת��Ϊ����ָ���������ӿ�
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://����ԤԼ
			stu->applyOrder();
			break;
		case 2://�鿴����ԤԼ
			stu->showMyOrder();
			break;
		case 3://�鿴ȫ��ԤԼ
			stu->showAllOrder();
			break;
		case 4://ȡ��ԤԼ
			stu->cancleOrder();
			break;
		default://ע��
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//������ʦ���˵��������
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//������ʦ�˵�
		teacher->operMenu();

		//������ָ��ת��Ϊ����ָ���������ĺ���
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://�鿴������ԤԼ
			tea->showAllOrder();
			break;
		case 2://���ԤԼ
			tea->validOrder();
			break;
		default://ע��
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����
void loginIn(string fileName, int type)
{
	//����ָ��ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//�û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "�������ѧ��: " << endl;
		cin >> id;
	}
    if (type == 2)
	{
		cout << "��������ְ����: " << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//��֤��Ϣ
	if (type == 1)
	{
		//ѧ�������֤
		
		//�ļ��е���Ϣ����
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl; 
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�����
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤

		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�����
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤

		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�����
				managerMenu(person);
				return;
			}
		}
	}

	cout << "�û���֤ʧ�ܣ� " << endl;
	system("pause");
	system("cls");
	return; 

}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "==================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ==================" << endl;
		cout << endl << " ������������ " << endl;

		cout << "\t\t_____________________________________\n";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           1.ѧ������              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           2.��    ʦ              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           3.�� �� Ա              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           0.��    ��              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t_____________________________________\n";

		cout << "�������ѡ��" << endl;
		cin >> select;

		switch (select)
		{
		case 1: //ѧ��
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			loginIn(ADMIN_FILE, 3);
		    break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		default:
			system("pause");
			system("cls");
			break;

		}

	}

	system("pause");
	return 0;
}