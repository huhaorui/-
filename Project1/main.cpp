#include <iostream>
#include "record.h"
#include "date_time.h"
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <string>
using namespace std;
record records[1000];
int k = 0;//总的记录数
date today()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	return d;
}
bool is_num(char c)
{
	if (c <= '9' && c >= '0')
		return true;
	else
		return false;
}
bool is_num(string s)
{
	for (int x = 0; x < s.length(); x++)
	{
		if (!is_num(s[x])) return false;
	}
	return true;
}
int to_int(string s)
{
	int n;
	stringstream sstr;
	sstr << s;
	sstr >> n;
	return n;
}
double to_double(string s)
{
	double n;
	stringstream sstr;
	sstr << s;
	sstr >> n;
	return n;
}
date_time now()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	date_time dt(d, t.tm_hour, t.tm_min, t.tm_sec);
	return dt;
}
void edit_num(int n)
{
	string num_building, num_house;
	cout << "请输入新的楼号与房号:";
	cin >> num_building;
	while (!is_num(num_building))
	{
		cout << "楼号输入有误，请重新输入:";
		cin.ignore(100, '\n');//清空cin流
		cin >> num_building;
	}
	cin >> num_house;
	while (!is_num(num_house))
	{
		cout << "房号输入有误，请重新输入:";
		cin.ignore(100, '\n');//清空cin流
		cin >> num_house;
	}
	records[n].edit_num(to_int(num_building), to_int(num_house));
}
void edit_date(int n)
{
	string day_later;
	cout << "请输入新的预约时间:（输入一个小于10的数n，表示n天后）";
	cin >> day_later;
	while (!is_num(day_later))
	{
		cout << "输入有误，请重新输入";
		cin.ignore(100, '\n');//清空cin流
		cin >> day_later;
	}
	if (to_int(day_later) < 10)
	{
		date date_tmp = today();
		for (int x = 0; x < to_int(day_later); x++)
		{
			date_tmp = date_tmp.tomorrow();
		}
		records[n].edit_date_yy(date_tmp);
	}
	else
	{
		int year = to_int(day_later);
		string month, day;
		cin >> month;
		while (!is_num(month))
		{
			cout << "月份输入有误，请重新输入:";
			cin.ignore(100, '\n');//清空cin流
			cin >> month;
		}
		cin >> day;
		while (!is_num(day))
		{
			cout << "日期输入有误，请重新输入:";
			cin.ignore(100, '\n');//清空cin流
			cin >> day;
		}
		records[n].edit_date_yy(date(year, to_int(month), to_int(day)));
	}
}
void edit_detail(int n)
{
	string detail;
	cout << "请输入维修内容： ";
	cin >> detail;
	records[n].edit_detail(detail);
}
void edit_money(int n)
{
	string money_income, money_outcome;
	cout << "请输入收费和成本： ";
	cin >> money_income;
	while (!is_num(money_income))
	{
		cout << "收费输入有误，请重新输入:";
		cin.ignore(100, '\n');//清空cin流
		cin >> money_income;
	}
	cin >> money_outcome;
	while (!is_num(money_outcome))
	{
		cout << "成本输入有误，请重新输入:";
		cin.ignore(100, '\n');//清空cin流
		cin >> money_outcome;
	}
	records[n].edit_money(to_double(money_income), to_double(money_outcome));
}
void edit_people(int n)
{
	string people;
	cout << "请输入检修人： ";
	cin >> people;
	records[n].edit_people(people);
}
void edit_remark(int n)
{
	string remark;
	cout << "请输入备注： ";
	cin >> remark;
	records[n].edit_remark(remark);
}
void edit_all(int n)
{
	edit_num(n);
	edit_date(n);
	edit_detail(n);
	edit_money(n);
	edit_people(n);
	edit_remark(n);
}
void init()
{
	k = 0;
	int num_building, num_house; //楼号，房号
	date date_yy, date_fact; //预约时间，实际时间
	string detail; //维修内容
	double money_income, money_outcome; //收费，成本
	string people; //检修人
	string remark; //备注	
	int done;
	ifstream infile;
	infile.open("database.dat", ios::in);
	while (infile >> num_building >> num_house >> date_yy >> date_fact >> detail >> money_income >> money_outcome >> people >> remark >> done)
	{
		records[k].set(num_building, num_house, date_yy, date_fact, detail, money_income, money_outcome, people, remark, done);
		k++;
	}
	infile.close();
}
bool cmp(record& a, record& b)
{
	return a < b;
}
void save_all()
{
	sort(records, records + k, cmp);
	ofstream outfile;
	outfile.open("database.dat", ios::out);
	outfile.close();
	for (int x = 0; x < k; x++)
	{
		records[x].save_to_file();
	}
	init();
}
void activity_edit(int n)
{
	string op;
	system("cls");
	records[n].show(n);
	cout << "\n请选择你要修改的项目\n";
	cout << "1.楼房号码\n2.预约时间\n3.维修内容\n4.收费与成本\n5.检修人\n6.备注\n7.全部\n8.退出\n";
	cout << "请一次性输入所有要修改的项目，如“135”\n";
	cin >> op;
	for (int x = 0; x < op.length(); x++)
	{
		string num_building, num_house; //楼号，房号
		date date_yy, date_fact; //预约时间，实际时间
		string detail; //维修内容
		string money_income, money_outcome; //收费，成本
		string people; //检修人
		string remark; //备注	
		string day_later;
		system("cls");
		records[n].show(n);
		switch (op[x])
		{
		case '1':edit_num(n); break;
		case '2':edit_date(n);break;
		case '3':edit_detail(n); break;
		case '4':edit_money(n); break;
		case '5':edit_people(n); break;
		case '6':edit_remark(n); break;
		case '7':edit_all(n); break;
		}
	}
	system("cls");
	records[n].show(n);
	save_all();
	cout << "操作成功完成\n";
	system("pause");
}
void activity_delete(int n)
{
	cout << "这个操作不可逆，确认删除这条记录吗？(y/n)\n";
	char yesno;
	cin >> yesno;
	if (yesno != 'y')
		cout << "操作已取消\n";
	else
	{
		for (int x = n; x < k - 1; x++)
		{
			records[x] = records[x + 1]; //未来考虑用链表实现
		}
		k--;
		save_all();
		cout << "操作已成功完成\n";
		system("pause");
	}
}
void activity_finish(int n)
{
	
	int t1, t2, t3;
	char c;
	cout << "请输入完成日期：(输入0即为今天) ";
	cin >> t1;
	if (t1 != 0)
	{
		cin >> t2 >> t3;
		date d(t1, t2, t3);
		cout << "确定完成操作了？(y/n)  ";
		cin >> c;
		if (c == 'y')
		{
			records[n].edit_date_fact(d);
			records[n].edit_done();
		}
		save_all();
		system("cls");
		records[n].show(n);
		cout << "\n操作已成功完成\n";
		system("pause");
	}
	else
	{
		cout << "确定完成操作了？(y/n)  ";
		cin >> c;
		if (c == 'y')
		{
			records[n].edit_date_fact(today());
			records[n].edit_done();
		}
		save_all();
		system("cls");
		records[n].show(n);
		cout << "\n操作已成功完成\n";
		system("pause");
	}
	
}
int operate() //操作起来！
{
	int n, t;
	cout << "请输入你要操作的ID：输入-1退出\n";
	cin >> n;
	if (n == -1)
	{
		return 0;
	}
	if (n >= k || n < 0)
	{
		cout << "输入错误\n";
		system("pause");
		return 1;
	}
	cout << "1.删除记录   2.修改记录  3.完工登记\n";
	cout << "请输入你要进行的操作： ";
	cin >> t;
	switch (t)
	{
	case 1:activity_delete(n); break;
	case 2:activity_edit(n); break;
	case 3:activity_finish(n); break;
	default:break;
	}
	return 0;
}
void new_record()
{
	system("cls");
	int num_building, num_house; //楼号，房号
	date date_yy, date_fact; //预约时间，实际时间
	string detail; //维修内容
	double money_income, money_outcome; //收费，成本
	string people; //检修人
	string remark; //备注	
	cout << "请输入楼号和房号\n";
	cin >> num_building >> num_house;
	cout << "请输入预约时间（输入一个小于10的数n，表示n天后）\n";
	int day_later;
	cin >> day_later;
	if (day_later < 10)
	{
		date date_tmp = today();
		for (int x = 0; x < day_later; x++)
		{
			date_tmp = date_tmp.tomorrow();
		}
		date_yy=date_tmp;
	}
	else
	{
		int year = day_later;
		int month, day;
		cin >> month >> day;
		date_yy=(date(year, month, day));
	}
	cout << "请输入维修内容\n";
	cin >> detail;
	cout << "请输入收费与成本价\n";
	cin >> money_income >> money_outcome;
	cout << "请分配检修员:\n";
	cin >> people;
	cout << "请输入备注:\n";
	cin >> remark;
	record new_record(num_building, num_house, date_yy, date_fact, detail, money_income, money_outcome, people, remark);
	new_record.save_to_file();
	system("cls");
	cout << "保存成功!记录如下：\n";
	new_record.show();
	init();
	system("pause");
}
void search_record()
{
	system("cls");
	string key;
	cout << "请输入你要查找的关键词\n";
	cin >> key;
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].exist(key))
		{
			records[x].show(x);
			n++;
			continue;
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "没有符合要求的记录\n";
		system("pause");
	}
}
void find_all_record()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		records[x].show(x);
		cout << '\n';
	}
	if (k != 0) 
		operate();
	else
	{
		cout << "没有符合要求的记录\n";
		system("pause");
	}
}
void fix_unfinished()
{
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished())
		{
			n++;
			records[x].show(x);
			cout << '\n';
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "没有符合要求的记录\n";
		system("pause");
	}
}
void fix_overdate()
{
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && records[x].overdate(today()))
		{
			records[x].show(x);
			cout << '\n';
			n++;
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "没有符合要求的记录\n";
		system("pause");
	}
}
void fix_two_days()
{
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && records[x].overdate(today().tomorrow().tomorrow().tomorrow()))
		{
			n++;
			records[x].show(x);
			cout << '\n';
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "没有符合要求的记录\n";
		system("pause");
	}
}
void intime_service()
{
	system("cls");
	cout << "1.显示所有未完成的维修\n";
	cout << "2.显示超期未完成的维修\n";
	cout << "3.显示两天内需要完成的维修\n";
	cout << "请输入你要显示的内容\n";
	int t;
	cin >> t;
	switch (t)
	{
	case 1:fix_unfinished(); break;
	case 2:fix_overdate(); break;
	case 3:fix_two_days(); break;
	}
}
void statistic_income_date()
{
	cout << "请输入你要统计的日期： ";
	date d;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> d;
	for (int x = 0; x < k; x++)
	{
		if (records[x].day_fact_is(d) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << "\n在这一天里，总共进行了" << num << "次维修，收到了" << total_income << "元，净盈利" << total_income - total_outcome << "元\n";
	system("pause");
}
void statistic_income_building()
{
	cout << "请输入你要统计的楼： ";
	int build;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> build;
	for (int x = 0; x < k; x++)
	{
		if (records[x].num_building_is(build) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << "\n对这栋楼，总共进行了" << num << "次维修，收到了" << total_income << "元，净盈利" << total_income - total_outcome << "元\n";
	system("pause");
}
void statistic_income_people()
{
	cout << "请输入你要统计的检修员姓名： ";
	string name;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> name;
	for (int x = 0; x < k; x++)
	{
		if (records[x].name_is(name) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << '\n' << name << "总共进行了" << num << "次维修，收到了" << total_income << "元，净盈利" << total_income - total_outcome << "元\n";
	system("pause");
}
void statistic_income()
{
	int n;
	cout << "1.按天统计\n";
	cout << "2.按楼统计\n";
	cout << "3.按检修员统计\n";
	cout << "请选择统计的维度： ";
	cin >> n;
	switch (n)
	{
	case 1: statistic_income_date(); break;
	case 2: statistic_income_building(); break;
	case 3: statistic_income_people(); break;
	}
}
int main()
{
	init();
	cout << "欢迎使用物业管理维修系统\n";
	while (true)
	{
		int c;
		save_all();
		init();
		now().show();
		cout << '\n';
		cout << "┌──────────────────┐\n";
		cout << "│ 1.新增记录       │\n";
		cout << "│ 2.搜索记录       │\n";
		cout << "│ 3.查看所有记录   │\n";
		cout << "│ 4.预约到期查询   │\n";
		cout << "│ 5.高级统计功能   │\n";
		cout << "│ 6.退出系统       │\n";
		cout << "└──────────────────┘\n";
		cout << "请输入你要使用的功能： ";
		cin >> c;
		switch (c) {
		case 1:new_record(); break;
		case 2:search_record(); break;
		case 3:find_all_record(); break;
		case 4:intime_service(); break;
		case 5:statistic_income(); break;
		case 6:save_all(); cout << "再见"; return 0; break;
		default:
			cout << "输入错误，请重新输入\n";
		}
		system("cls");
	}
}