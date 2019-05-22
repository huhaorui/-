#pragma once
#include "date.h"
#include <string>
class record
{
private:
	int num_l, num_f; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_income, money_outcome; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע
	bool done; //�Ƿ��Ѿ����
public:
	string show_in_line();
	void save_to_file();
	void show();
	void edit_num(int, int);
	void edit_date_yy(date);
	void edit_date_fact(date);
	void edit_detail(string);
	void edit_money(double, double);
	void edit_people(string);
	void edit_remark(string);
	void edit_done();
	bool unfinished();
	bool overdate(date);
	bool day_fact_is(date);
	bool num_l_is(int n)
	{
		if (n == num_l) return true; else return false;
	}
	bool name_is(string s)
	{
		if (s == people) return true; else return false;
	}
	bool exist(string s);//�ж��Ƿ�����Ӵ�
	double get_income()
	{
		return money_income;
	}
	double get_outcome()
	{
		return money_outcome;
	}
	void set(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done = 0);
	record();
	record(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done = 0);
	~record();
};

