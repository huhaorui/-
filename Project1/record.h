#pragma once
#include "date.h"
#include <string>
using namespace std;
class record
{
private:
	int num_l, num_f; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_get,money_used; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע
public:
	string show_in_line();
	record();
	~record();
};

