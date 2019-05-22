#include <iostream>
#include "record.h"
#include <cstdio>
#include <fstream>
using namespace std;
void new_record()
{
	int num_l, num_f; //楼号，房号
	date date_yy, date_fact; //预约时间，实际时间
	string detail; //维修内容
	double money_get, money_used; //收费，成本
	string people; //检修人
	string remark; //备注	
	cout << "请输入楼号和房号\n";
	cin >> num_l >> num_f;
	cout << "请输入预约时间\n";
	cin >> date_yy;
	cout << "请输入维修内容\n";
	cin >> detail;
	cout << "请输入收费与成本价\n";
	cin >> money_get >> money_used;
	cout << "请分配检修员:\n";
	cin >> people;
	cout << "请输入备注:\n";
	cin >> remark;
	record new_record(num_l, num_f, date_yy, date_fact, detail, money_get, money_used, people, remark);
	new_record.save_to_file();
}
void search_record()
{

}
void find_all_record()
{

}
void intime_service()
{

}
void advanced_feature()
{

}
int main()
{
	cout << "欢迎使用物业管理维修系统\n";
	while (true)
	{
		int c;
		cout << "1.新增记录\n";
		cout << "2.搜索记录\n";
		cout << "3.查看所有记录\n";
		cout << "4.预约到期查询\n";
		cout << "5.高级统计功能\n";
		cout << "6.退出系统\n";
		cout << "请输入你要使用的功能：";
		cin >> c;
		switch (c){
		case 1:new_record(); break;
		case 2:search_record(); break;
		case 3:find_all_record(); break;
		case 4:intime_service(); break;
		case 5:advanced_feature(); break;
		case 6:cout << "再见"; return 0; break;
		default:
			cout << "输入错误，请重新输入\n";

		}
		system("cls");
	}
}