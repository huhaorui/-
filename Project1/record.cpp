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
	cout << "λ��\t��" << num_l << "¥��" << num_f << "��\n";
	cout << "ԤԼʱ�䣺";
	date_yy.show();
	cout << "\nά�����ݣ�" << detail << '\n';
	cout << "�շ�\t��" << money_get << '\n';
	cout << "�ɱ�\t��" << money_used << '\n';
	cout << "ά��Ա\t��" << people << '\n';
	cout << "��ע\t��" << remark << '\n';
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
