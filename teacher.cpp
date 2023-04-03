#include "teacher.h"

//无参构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_Empid = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎学生代表" << this->m_Name << "登录!" << endl;
	cout << "\t\t_____________________________________\n";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           1.查 看 所 有 预 约     |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           2.审 核 预 约           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           0.注 销 登 录           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t_____________________________________\n";
	cout << "请选择你的操作" << endl;
}

//查看所有人的预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << " ";
		cout << "预约日期： 周" << of.m_OrderData[i]["date"];
		cout << "  预约时段： " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  学号： " << of.m_OrderData[i]["stuId"];
		cout << "  姓名： " << of.m_OrderData[i]["stuName"];
		cout << "  机房号： " << of.m_OrderData[i]["roomId"];
		//状态说明
		//1 审核中   2 已预约   -1 预约失败  0 取消预约
		string status = "  状态： ";
		if (of.m_OrderData[i]["status"] == "1") status += "审核中";
		else if (of.m_OrderData[i]["status"] == "2") status += "已预约";
		else if (of.m_OrderData[i]["status"] == "-1") status += "预约失败";
		else status += "预约取消";
		cout << status << endl;
	}
	system("pause");
	system("cls");
	return;
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;
	vector<int> v;
	cout << "审核中的预约记录如下：" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		//判断预约状态是否为审核中
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << " ";
			cout << "预约日期： 周" << of.m_OrderData[i]["date"];
			cout << "  预约时段： " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  机房号： " << of.m_OrderData[i]["roomId"];
			string status = "  状态： ";
			if (of.m_OrderData[i]["status"] == "1") status += "审核中";
			cout << status << endl;
		}
	}

	int select = 0;
	int ret = 0;
	while (true)
	{
		cout << "输入审核的预约记录，0代表返回" << endl;
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
				cout << "请输入审核的结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1) of.m_OrderData[v[select - 1]]["status"] = "2";
				else if (ret == 2) of.m_OrderData[v[select - 1]]["status"] = "-1";
				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}