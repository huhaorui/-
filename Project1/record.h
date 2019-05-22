#pragma once
#include "date.h"
#include <string>
class record
{
private:
	int num_l, num_f; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_get,money_used; //�շѣ��ɱ�
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
	bool exist(string s);//�ж��Ƿ�����Ӵ�
	void set(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_get, double s_money_used, string s_people, string  s_remark, bool s_done = 0);
	record();
	record(int s_num_l, int s_num_f, date s_date_yy, date s_date_fact, string s_detail, double s_money_get, double s_money_used, string s_people, string  s_remark,bool s_done=0);
	~record();
};

