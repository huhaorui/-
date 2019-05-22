#include "record.h"
#include <iostream>
using namespace std;
string record::show_in_line()
{
	string s;
	return s;
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


record::~record()
{
}
