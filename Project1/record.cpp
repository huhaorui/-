#include "record.h"
#include "function.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
string record::show_in_line()
{
	string s = "";
	s = to_string(num_building) + ' ' + to_string(num_house) + ' ' + date_reserve.out() + ' ' + date_fact.out() + ' ' + content + ' ' + to_string(money_income) + ' ' + to_string(money_outcome) + ' ' + people + ' ' + remark + ' ' + to_string(done) + '\n';
	return s;
}
void record::show()
{
	cout << "位置\t： " << num_building << "号楼，" << num_house << "房\n";
	cout << "预约时间： ";
	date_reserve.show();
	if (done)
	{
		cout << "\n完成时间： ";
		date_fact.show();
	}
	cout << "\n维修内容： " << content << '\n';
	cout << "收费\t： " << money_income << '\n';
	cout << "成本\t： " << money_outcome << '\n';
	cout << "维修员\t： " << people << '\n';
	cout << "备注\t： " << remark << '\n';
	cout << "状态\t： ";
	if (done) cout << "已完成\n"; else cout << "未完成\n";
	cout << '\n';
}
void record::show(int n)
{
	cout << "ID\t： " << n << '\n';
	cout << "位置\t： " << num_building << "号楼，" << num_house << "房\n";
	cout << "预约时间： ";
	date_reserve.show();
	if (done)
	{
		cout << "\n完成时间： ";
		date_fact.show();
	}
	cout << "\n维修内容： " << content << '\n';
	cout << "收费\t： " << money_income << '\n';
	cout << "成本\t： " << money_outcome << '\n';
	cout << "维修员\t： " << people << '\n';
	cout << "备注\t： " << remark << '\n';
	cout << "状态\t： ";
	if (done) cout << "已完成\n"; else cout << "未完成\n";
	cout << "────────────────────────────────────────────\n";
}
void record::edit_num(int a, int b)
{
	num_building = a;
	num_house = b;
}
void record::edit_date_reserve(date d)
{
	date_reserve = d;
}
void record::edit_date_fact(date d)
{
	date_fact = d;
}
void record::edit_content(string s)
{
	content = s;
}
void record::edit_money(double a, double b)
{
	money_income = a;
	money_outcome = b;
}
void record::edit_people(string s)
{
	people = s;
}
void record::edit_remark(string s)
{
	remark = s;
}
void record::edit_done()
{
	done = true;
}
void record::save_to_file()
{
	ofstream outfile;
	outfile.open("database.dat", ios::app);
	outfile << num_building << ' ' << num_house << ' ' << date_reserve << ' ' << date_fact << ' ' << content << ' ' << money_income << ' ' << money_outcome << ' ' << people << ' ' << remark << ' ' << done << '\n';
	outfile.close();
}
bool record::unfinished()
{
	return !done;
}
bool record::overdate(date d)
{
	if (d > date_reserve) return true;
	return false;
}
bool record::day_fact_is(date d)
{
	if (d == date_fact) return true; else return false;
}
record::record()
{
	num_building = 0;
	num_house = 0;
	content = "";
	money_income = 0;
	money_outcome = 0;
	people = "";
	remark = "";
	done = 0;
}
record::record(int s_num_building, int s_num_house, date s_date_reserve, date s_date_fact, string s_content, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done)
{
	num_building = s_num_building;
	num_house = s_num_house;
	date_reserve = s_date_reserve;
	date_fact = s_date_fact;
	content = s_content;
	money_income = s_money_income;
	money_outcome = s_money_outcome;
	people = s_people;
	remark = s_remark;
	done = s_done;
}

void record::set(int s_num_building, int s_num_house, date s_date_reserve, date s_date_fact, string s_content, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done)
{
	num_building = s_num_building;
	num_house = s_num_house;
	date_reserve = s_date_reserve;
	date_fact = s_date_fact;
	content = s_content;
	money_income = s_money_income;
	money_outcome = s_money_outcome;
	people = s_people;
	remark = s_remark;
	done = s_done;
}
bool record::exist(string s)
{
	if (content.find(s) != string::npos) return true;
	if (people.find(s) != string::npos) return true;
	if (remark.find(s) != string::npos) return true;
	if (toString(num_building).find(s) != string::npos) return true;
	if (toString(num_house).find(s) != string::npos) return true;
	if (toString(money_income).find(s) != string::npos) return true;
	if (toString(money_outcome).find(s) != string::npos) return true;
	if (date_fact.out().find(s) != string::npos) return true;
	if (date_reserve.out().find(s) != string::npos) return true;
	if (is_proper_num(s))
	{
		date d = today();
		for (int x = 0; x < to_int(s); x++)
		{
			d = d.tomorrow();
		}
		if (d == date_fact || d == date_reserve) return true;
	}
	return false;
}
record::~record()
{
}
