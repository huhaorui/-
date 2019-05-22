#include <iostream>
#include "record.h"
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <sstream>
using namespace std;
record records[1000];
int k=0;

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
void activity_delete(int n)//存在未知bug？？
{
	cout << "这个操作不可逆转，确认删除这条记录吗？(y/n)\n";
	char yesno;
	cin >> yesno;
	if (yesno != 'y')
		cout << "操作已取消\n";
	else
		for (int x = n; x < k - 1; n++)
		{
			records[x] = records[x + 1]; //未来考虑用链表实现
		}
	ofstream outfile;
	outfile.open("datebase.dat", ios::out);
	outfile.close();
	k--;
	for (int x = 0; x < k; x++)
	{
		records[x].save_to_file();
	}
	init();
}
void operate()
{
	int n, t;
	system("cls");
	cout << "请输入你要操作的序号：输入-1退出\n";
	cin >> n;
	if (n >= k || n < 0) cout << "输入错误\n";
	cout << "请输入你要进行的操作：\n";
	cout << "1.删除记录   2.修改记录 ";
	cin >> t;
	switch (t)
	{
	case 1:activity_delete(n); break;
	case 2:break;
	default:break;
	}
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
	system("pause");
}
void intime_service()
{
	
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
		case 6:cout << "再见"; return 0; break;
		default:
			cout << "输入错误，请重新输入\n";

		}
		system("cls");
	}
}