#include "student.h"

//无参构造
Student::Student()
{

}

//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生代表" << this->m_Name << "登录!" << endl;
	cout << "\t\t_____________________________________\n";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           1.申 请 预 约           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           2.查 看 我 的 预 约     |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           3.查 看 所 有 预 约     |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           4.取 消 预 约           |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|                                   |\n ";
	cout << "\t\t|           0.注 销 登 录           |\n ";
	cout << "\t\t_____________________________________\n";
	cout << "请选择你的操作" << endl;
}

//申请预约
void Student::applyOrder()
{
	int date;    //预约日期
	int interval;//预约时段
	int room;    //预约机房号

	cout << "机房预约的日期是周一至周五" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	cout << "请输入预约的日期" << endl;
	cin >> date;
	while (true)
	{
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "时间错误,请重新输入！" << endl;
	}

	cout << "机房预约的时段如下:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	cout << "请输入预约时段" << endl;
	cin >> interval;
	while (true)
	{
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "时段错误，请重新输入!" << endl;
	}

	cout << "机房信息如下：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "号机房的最大容量是：" << vCom[i].m_MaxNum << endl;
	}
	cout << "请输入预约的机房号" << endl;
	cin >> room;
	while (true)
	{
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "机房号有误，请重新输入！" << endl;
	}

	cout << "预约成功，正在审核中！" << endl;

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

//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//string 转为 int
		//string 利用 .c_str()转为 const char*
		//利用atoi (const char*)转为 int
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			cout << "预约日期:  周" << of.m_OrderData[i]["date"];
			cout << "  预约时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  机房号：" << of.m_OrderData[i]["roomId"];
			//状态说明
			//1 审核中   2 已预约   -1 预约失败  0 取消预约
			string status = "  状态： ";
			if (of.m_OrderData[i]["status"] == "1") status += "审核中";
			else if (of.m_OrderData[i]["status"] == "2") status += "已预约";
			else if (of.m_OrderData[i]["status"] == "-1") status += "预约失败";
			else status += "预约取消";
			cout << status << endl;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
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
		cout << "  预约时段: " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
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
	cout << endl;
	system("pause");
	system("cls");
}

//取消预约
void Student::cancleOrder()
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
	for (int i = 0; i < of.m_Size; i++)
	{
		//判断是否是自身
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//判断是否是审核状态或者预约成功状态
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << " ";
				cout << "预约日期:  周" << of.m_OrderData[i]["date"];
				cout << "  预约时段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "  机房号： " << of.m_OrderData[i]["roomId"];
				string status = "  状态: ";
				if (of.m_OrderData[i]["status"] == "1") status += "审核中";
				else if (of.m_OrderData[i]["status"] == "2") status += "已预约";
				cout << status << endl;
			}
		}
	}

	while (true)
	{
		cout << "请选择要取消的预约记录，0代表返回" << endl;
		int select = 0;
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0) break;
			else 
			{
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "取消预约成功" << endl;
				break;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

	system("pause");
	system("cls");
}
