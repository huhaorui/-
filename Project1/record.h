#pragma once
#include "date.h"
#include <string>
class record
{
private:
	int num_l, num_f; //楼号，房号
	date date_yy, date_fact; //预约时间，实际时间
	string detail; //维修内容
	double money_get,money_used; //收费，成本
	string people; //检修人
	string remark; //备注
public:
	string show_in_line();
	record(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_get, double s_money_used, string s_people, string  s_remark);
	~record();
};

