#include "record.h"
#include <iostream>
#include <fstream>
using namespace std;
string record::show_in_line()
{
	string s;
	return s;
}
void record::show()
{
	cout << "位置\t：" << num_l << "楼，" << num_f << "房\n";
	cout << "预约时间：";
	date_yy.show();
	cout << "\n维修内容：" << detail << '\n';
	cout << "收费\t：" << money_get << '\n';
	cout << "成本\t：" << money_used << '\n';
	cout << "维修员\t：" << people << '\n';
	cout << "备注\t：" << remark << '\n';
}
void record::save_to_file()
{
	ofstream outfile;
	outfile.open("datebase.dat", ios::app);
	outfile << num_l << ' ' << num_f << ' ' << date_yy << ' ' << date_fact << ' ' << detail << ' ' << money_get << ' ' << money_used << ' ' << people << ' ' << remark << '\n';
	outfile.close();
}
record::record()
{
	num_l = 0;
	num_f = 0;
	detail = "";
	money_get = 0;
	money_used = 0;
	people = "";
	remark = "";
}
record::record(int s_num_l,int s_num_f,date s_date_yy,date s_date_fact,string s_detail,double s_money_get,double s_money_used,string s_people,string  s_remark)
{
	num_l = s_num_l;
	num_f = s_num_f;
	date_yy = s_date_yy;
	date_fact = s_date_fact;
	detail = s_detail;
	money_get = s_money_get;
	money_used = s_money_used;
	people = s_people;
	remark = s_remark;
}

void record::set(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_get, double s_money_used, string s_people, string  s_remark)
{
	num_l = s_num_l;
	num_f = s_num_f;
	date_yy = s_date_yy;
	date_fact = s_date_fact;
	detail = s_detail;
	money_get = s_money_get;
	money_used = s_money_used;
	people = s_people;
	remark = s_remark;
}
bool record::exist(string s)
{
	if (detail.find(s) != string::npos) return true;
	if (people.find(s) != string::npos) return true;
	if (remark.find(s) != string::npos) return true;
	return false;
}
record::~record()
{
}
