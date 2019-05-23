#include "record.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string toString(int n)
{
	stringstream sstr;
	sstr << n;
	string str = sstr.str();
	return str;
}
string record::show_in_line()
{
	string s;
	return s;
}
void record::show()
{
	cout << "λ��\t�� " << num_l << "��¥��" << num_f << "��\n";
	cout << "ԤԼʱ�䣺 ";
	date_yy.show();
	if (done)
	{
		cout << "\n���ʱ�䣺 ";
		date_fact.show();
	}
	cout << "\nά�����ݣ� " << detail << '\n';
	cout << "�շ�\t�� " << money_income << '\n';
	cout << "�ɱ�\t�� " << money_outcome << '\n';
	cout << "ά��Ա\t�� " << people << '\n';
	cout << "��ע\t�� " << remark << '\n';
	cout << "״̬\t�� ";
	if (done) cout << "�����\n"; else cout << "δ���\n";
	cout << '\n';
}
void record::show(int n)
{
	cout << "ID\t�� " << n << '\n';
	cout << "λ��\t�� " << num_l << "��¥��" << num_f << "��\n";
	cout << "ԤԼʱ�䣺 ";
	date_yy.show();
	if (done)
	{
		cout << "\n���ʱ�䣺 ";
		date_fact.show();
	}
	cout << "\nά�����ݣ� " << detail << '\n';
	cout << "�շ�\t�� " << money_income << '\n';
	cout << "�ɱ�\t�� " << money_outcome << '\n';
	cout << "ά��Ա\t�� " << people << '\n';
	cout << "��ע\t�� " << remark << '\n';
	cout << "״̬\t�� ";
	if (done) cout << "�����\n"; else cout << "δ���\n";
	cout << "����������������������������������������������������������������������������������������\n";
}
void record::edit_num(int a, int b)
{
	num_l = a;
	num_f = b;
}
void record::edit_date_yy(date d)
{
	date_yy = d;
}
void record::edit_date_fact(date d)
{
	date_fact = d;
}
void record::edit_detail(string s)
{
	detail = s;
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
	outfile << num_l << ' ' << num_f << ' ' << date_yy << ' ' << date_fact << ' ' << detail << ' ' << money_income << ' ' << money_outcome << ' ' << people << ' ' << remark << ' ' << done << '\n';
	outfile.close();
}
bool record::unfinished()
{
	return !done;
}
bool record::overdate(date d)
{
	if (d > date_yy) return true;
	return false;
}
bool record::day_fact_is(date d)
{
	if (d == date_fact) return true; else return false;
}
record::record()
{
	num_l = 0;
	num_f = 0;
	detail = "";
	money_income = 0;
	money_outcome = 0;
	people = "";
	remark = "";
	done = 0;
}
record::record(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done)
{
	num_l = s_num_l;
	num_f = s_num_f;
	date_yy = s_date_yy;
	date_fact = s_date_fact;
	detail = s_detail;
	money_income = s_money_income;
	money_outcome = s_money_outcome;
	people = s_people;
	remark = s_remark;
	done = s_done;
}

void record::set(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done)
{
	num_l = s_num_l;
	num_f = s_num_f;
	date_yy = s_date_yy;
	date_fact = s_date_fact;
	detail = s_detail;
	money_income = s_money_income;
	money_outcome = s_money_outcome;
	people = s_people;
	remark = s_remark;
	done = s_done;
}
bool record::exist(string s)
{
	if (detail.find(s) != string::npos) return true;
	if (people.find(s) != string::npos) return true;
	if (remark.find(s) != string::npos) return true;
	if (toString(num_l).find(s) != string::npos) return true;
	if (toString(num_f).find(s) != string::npos) return true;
	if (toString(money_income).find(s) != string::npos) return true;
	if (toString(money_outcome).find(s) != string::npos) return true;
	return false;
}
record::~record()
{
}
