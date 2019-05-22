#include <iostream>
#include "record.h"
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <time.h>
using namespace std;
record records[1000];
int k=0;//总的记录数
date today()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	return d;
}
void init()
{
	k = 0;
	int num_l, num_f; //楼号，房号
	date date_yy, date_fact; //预约时间，实际时间
	string detail; //维修内容
	double money_get, money_used; //收费，成本
	string people; //检修人
	string remark; //备注	
	int done;
	ifstream infile;
	infile.open("datebase.dat", ios::in);
	while (infile >> num_l >> num_f >> date_yy >> date_fact >> detail >> money_get >> money_used >> people >> remark >> done)
	{
		records[k].set(num_l, num_f, date_yy, date_fact, detail, money_get, money_used, people, remark, done);
		k++;
	}
	infile.close();
}
void save_all()
{
	ofstream outfile;
	outfile.open("datebase.dat", ios::out);
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
	records[n].show();
	cout << "\n请选择你要修改的项目\n";
	cout << "1.楼房号码\n2.预约时间\n3.维修内容\n4.收费与成本\n5.检修人\n6.备注\n7.全部\n8.退出\n";
	cout << "请一次性输入所有要修改的项目，如“135”\n";
	cin >> op;
	for (int x = 0; x < op.length(); x++)
	{
		int num_l, num_f; //楼号，房号
		date date_yy, date_fact; //预约时间，实际时间
		string detail; //维修内容
		double money_get, money_used; //收费，成本
		string people; //检修人
		string remark; //备注	
		system("cls");
		records[n].show();
		switch (op[x])
		{
		case '1':
			cout << "请输入新的楼号与房号:";
			cin >> num_l >> num_f;
			records[n].edit_num(num_l, num_f);
			break;
		case '2':
			cout << "请输入新的预约时间:";
			cin >> date_yy;
			records[n].edit_date_yy(date_yy);
			break;
		case '3':
			cout << "请输入维修内容：";
			cin >> detail;
			records[n].edit_detail(detail);
			break;
		case '4':
			cout << "请输入收费和成本：";
			cin >> money_get >> money_used;
			records[n].edit_money(money_get, money_used);
			break;
		case '5':
			cout << "请输入检修人：";
			cin >> people;
			records[n].edit_people(people);
			break;
		case '6':
			cout << "请输入备注：";
			cin >> remark;
			records[n].edit_remark(remark);
			break;
		case '7':
			cout << "请输入新的楼号与房号:";
			cin >> num_l >> num_f;
			records[n].edit_num(num_l, num_f);
			cout << "请输入新的预约时间:";
			cin >> date_yy;
			records[n].edit_date_yy(date_yy);
			cout << "请输入维修内容：";
			cin >> detail;
			records[n].edit_detail(detail);
			cout << "请输入收费和成本：";
			cin >> money_get >> money_used;
			records[n].edit_money(money_get, money_used);
			cout << "请输入检修人：";
			cin >> people;
			records[n].edit_people(people);
			cout << "请输入备注：";
			cin >> remark;
			records[n].edit_remark(remark);
		case '8':
		default:;
		}
	}
	save_all();
	system("cls");
	cout << "操作成功完成\n";
	records[n].show();
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
		for (int x = n; x < k - 1; x++)
		{
			records[x] = records[x + 1]; //未来考虑用链表实现
		}
	k--;
	save_all();
}
void activity_finish(int n)
{
	date d;
	char c;
	cout << "请输入完成日期：";
	cin >> d;
	cout << "确定完成操作了？(y/n)  ";
	cin >> c;
	if (c == 'y')
	{
		records[n].edit_date_fact(d);
		records[n].edit_done();
	}
	save_all();
	system("cls");
	records[n].show();
	cout << "\n操作已成功完成\n";
	system("pause");
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
	cout << "请输入你要进行的操作：";
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
	for (int x = 0; x < k; x++)
	{
		if (records[x].exist(key))
		{
			cout << "ID\t：" << x << '\n';
			records[x].show();
			cout << '\n';
			continue;
		}
	}
	operate();
}
void find_all_record()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		cout << "ID\t：" << x << '\n';
		records[x].show();
		cout << '\n';
	}
	operate();
}
void fix_unfinished()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished())
		{
			cout << "ID\t：" << x << '\n';
			records[x].show();
			cout << '\n';
		}
	}
	operate();
}
void fix_overdate()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished()&&records[x].overdate(today()))
		{
			cout << "ID\t：" << x << '\n';
			records[x].show();
			cout << '\n';
		}
	}
	operate();
}
void fix_two_days()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && records[x].overdate(today().tomorrow().tomorrow().tomorrow()))
		{
			cout << "ID\t：" << x << '\n';
			records[x].show();
			cout << '\n';
		}
	}
	operate();
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
void advanced_feature()
{

}
int main()
{
	init();
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
		case 6:save_all(); cout << "再见"; return 0; break;
		default:
			cout << "输入错误，请重新输入\n";
		}
		system("cls");
	}
}