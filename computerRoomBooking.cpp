#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入管理员子菜单界面
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//调用管理员的子菜单
		manager->operMenu(); 

		//将父类指针转化为子类指针调用子类接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://添加账号
			man->addPerson();
		    break;
		case 2://查看账号
			man->showPerson();
			break;
		case 3://查看机房信息
			man->showComputer();
			break;
		case 4://清空预约记录
			man->clearFile();
			break;
		default://注销
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//进入学生主菜单管理界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//显示学生菜单
		student->operMenu();

		//将父类指针转化为子类指针调用子类接口
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://申请预约
			stu->applyOrder();
			break;
		case 2://查看自身预约
			stu->showMyOrder();
			break;
		case 3://查看全部预约
			stu->showAllOrder();
			break;
		case 4://取消预约
			stu->cancleOrder();
			break;
		default://注销
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入老师主菜单管理界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用老师菜单
		teacher->operMenu();

		//将父类指针转化为子类指针调用自身的函数
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://查看所有人预约
			tea->showAllOrder();
			break;
		case 2://审核预约
			tea->validOrder();
			break;
		default://注销
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能
void loginIn(string fileName, int type)
{
	//父类指针指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "输入你的学号: " << endl;
		cin >> id;
	}
    if (type == 2)
	{
		cout << "输入您的职工号: " << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//验证信息
	if (type == 1)
	{
		//学生身份验证
		
		//文件中的信息变量
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl; 
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单界面
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证

		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单界面
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证

		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单界面
				managerMenu(person);
				return;
			}
		}
	}

	cout << "用户验证失败！ " << endl;
	system("pause");
	system("cls");
	return; 

}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "==================  欢迎来到传智播客机房预约系统  ==================" << endl;
		cout << endl << " 请输入你的身份 " << endl;

		cout << "\t\t_____________________________________\n";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           1.学生代表              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           2.老    师              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           3.管 理 员              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|           0.退    出              |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t|                                   |\n ";
		cout << "\t\t_____________________________________\n";

		cout << "输入你的选择" << endl;
		cin >> select;

		switch (select)
		{
		case 1: //学生
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://教师
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			loginIn(ADMIN_FILE, 3);
		    break;
		case 0://退出系统
			cout << "欢迎下次使用！" << endl;
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