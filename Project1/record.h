#pragma once
#include "date.h"
#include <string>
class record
{
protected:
	int num_building, num_house; //楼号，房号
	date date_yy, date_fact; //预约时间，实际时间
	string detail; //维修内容
	double money_income, money_outcome; //收费，成本
	string people; //检修人
	string remark; //备注
	bool done; //是否已经完成
public:
	string show_in_line();
	friend bool operator <(record& r1, record& r2)
	{
		return r1.date_yy < r2.date_yy;
	}
	friend bool operator >(record& r1, record& r2)
	{
		return r1.date_yy > r2.date_yy;
	}
	void save_to_file();
	void show();
	void show(int);
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
	bool num_building_is(int n)
	{
		if (n == num_building) return true; else return false;
	}
	bool name_is(string s)
	{
		if (s == people) return true; else return false;
	}
	bool exist(string s);//判断是否存在子串
	double get_income()
	{
		return money_income;
	}
	double get_outcome()
	{
		return money_outcome;
	}
	void set(int s_num_building, int s_num_house, date s_date_yy, date s_date_fact, string s_detail, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done = 0);
	record();
	record(int s_num_building, int s_num_house, date s_date_yy, date s_date_fact, string s_detail, double s_money_income, double s_money_outcome, string s_people, string  s_remark, bool s_done = 0);
	~record();
};

