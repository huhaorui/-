#pragma once
#include "date.h"
#include <string> 
class record
{
protected:
	int num_building, num_house; //¥�ţ�����
	date date_reserve, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string content; //ά������
	double money_income, money_outcome; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע
	bool done; //�Ƿ��Ѿ����
public:
	string show_in_line();
	friend bool operator <(record& r1, record& r2)
	{
		return r1.date_reserve < r2.date_reserve;
	}
	friend bool operator >(record& r1, record& r2)
	{
		return r1.date_reserve > r2.date_reserve;
	}
	void save_to_file();
	void show();
	void show(int);
	void edit_num(int, int);
	void edit_date_reserve(date);
	void edit_date_fact(date);
	void edit_content(string);
	void edit_money(double, double);
	void edit_people(string);
	void edit_remark(string);
	void edit_done();
	bool unfinished();
	bool overdate(date);
	bool day_fact_is(date);
	bool num_building_is(int n)
	{
		return n == num_building;
	}
	bool name_is(string s)
	{
		return s == people;
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
	void set(int s_num_building, int s_num_house, date s_date_reserve, date s_date_fact, string s_content, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done = 0);
	record();
	record(int s_num_building, int s_num_house, date s_date_reserve, date s_date_fact, string s_content, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done = 0);
	~record();
};