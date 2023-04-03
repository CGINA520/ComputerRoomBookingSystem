#include "manager.h"

//无参构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();

	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量是：" << vCom.size() << endl;
}

//菜单
void Manager::operMenu()
{
	cout << "欢迎管理员" << this->m_Name << "登录!" << endl;
	cout << "\t\t_____________________________________\n";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           1.添 加 账 号           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           2.查 看 账 号           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           3.查 看 机 房           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           4.清 空 预 约           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           0.注 销 登 录           |\n ";
	cout << "\t\t_____________________________________\n";
	cout << "请选择你的操作" << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请选择要添加的用户" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号";
		errorTip = "职工号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	//写文件
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	ofs.close();
	system("pause");
	system("cls");

	this->initVector();
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << "  姓名：" << s.m_Name << "  密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_Empid << "  姓名：" << t.m_Name << "  密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有的学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有的教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "  机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//初始化容器
	vStu.clear();
	vTea.clear();

	ifstream ifs;

	//获取信息  学生
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "学生数量是：" << vStu.size() << endl;
	ifs.close();

	//获取信息  老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_Empid && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "老师数量是：" << vTea.size() << endl;
	ifs.close();
	
}

//查重
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_Empid)
			{
				return true;
			}
		}
	}

	return false;
}