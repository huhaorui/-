#include <iostream>
#include "record.h"
#include "date_time.h"
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <string>
using namespace std;
record records[1000];
int k = 0;//�ܵļ�¼��
date today()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	return d;
}
bool is_num(char c)
{
	if (c <= '9' && c >= '0')
		return true;
	else
		return false;
}
bool is_num(string s)
{
	if (!is_num(s[0]) && s[0] != '-') return false;
	for (int x = 1; x < s.length(); x++)
	{
		if (!is_num(s[x]) && s[x] != '.') return false;
	}
	return true;
}
int to_int(string s)
{
	int n;
	stringstream sstr;
	sstr << s;
	sstr >> n;
	return n;
}
double to_double(string s)
{
	double n;
	stringstream sstr;
	sstr << s;
	sstr >> n;
	return n;
}
date_time now()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	date_time dt(d, t.tm_hour, t.tm_min, t.tm_sec);
	return dt;
}
void edit_num(int n)//ɵ�Ӱ�ȫ
{
	string num_building, num_house;
	cout << "�������µ�¥���뷿��:";
	cin >> num_building;
	while (!is_num(num_building))
	{
		cout << "¥��������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> num_building;
	}
	cin >> num_house;
	while (!is_num(num_house))
	{
		cout << "����������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> num_house;
	}
	records[n].edit_num(to_int(num_building), to_int(num_house));
}
void edit_date(int n)//ɵ�Ӱ�ȫ
{
	string day_later;
	cout << "�������µ�ԤԼʱ��:������һ��С��10����n����ʾn���";
	cin >> day_later;
	while (!is_num(day_later))
	{
		cout << "������������������";
		cin.ignore(100, '\n');//���cin��
		cin >> day_later;
	}
	if (to_int(day_later) < 10)
	{
		date date_tmp = today();
		for (int x = 0; x < to_int(day_later); x++)
		{
			date_tmp = date_tmp.tomorrow();
		}
		records[n].edit_date_yy(date_tmp);
	}
	else
	{
		int year = to_int(day_later);
		string month, day;
		cin >> month;
		while (!is_num(month))
		{
			cout << "�·�������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> month;
		}
		cin >> day;
		while (!is_num(day))
		{
			cout << "����������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> day;
		}
		records[n].edit_date_yy(date(year, to_int(month), to_int(day)));
	}
}
void edit_detail(int n)//ɵ�Ӱ�ȫ
{
	string detail;
	cout << "������ά�����ݣ� ";
	cin >> detail;
	records[n].edit_detail(detail);
}
void edit_money(int n)//ɵ�Ӱ�ȫ
{
	string money_income, money_outcome;
	cout << "�������շѺͳɱ��� ";
	cin >> money_income;
	while (!is_num(money_income))
	{
		cout << "�շ�������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> money_income;
	}
	cin >> money_outcome;
	while (!is_num(money_outcome))
	{
		cout << "�ɱ�������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> money_outcome;
	}
	records[n].edit_money(to_double(money_income), to_double(money_outcome));
}
void edit_people(int n)//ɵ�Ӱ�ȫ
{
	string people;
	cout << "����������ˣ� ";
	cin >> people;
	records[n].edit_people(people);
}
void edit_remark(int n)//ɵ�Ӱ�ȫ
{
	string remark;
	cout << "�����뱸ע�� ";
	cin >> remark;
	records[n].edit_remark(remark);
}
void edit_all(int n)//ɵ�Ӱ�ȫ
{
	edit_num(n);
	edit_date(n);
	edit_detail(n);
	edit_money(n);
	edit_people(n);
	edit_remark(n);
}
void init()//ɵ�Ӱ�ȫ
{
	k = 0;
	int num_building, num_house; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_income, money_outcome; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	int done;
	ifstream infile;
	infile.open("database.dat", ios::in);
	while (infile >> num_building >> num_house >> date_yy >> date_fact >> detail >> money_income >> money_outcome >> people >> remark >> done)
	{
		records[k].set(num_building, num_house, date_yy, date_fact, detail, money_income, money_outcome, people, remark, done);
		k++;
	}
	infile.close();
}
bool cmp(record& a, record& b)
{
	return a < b;
}
void save_all()//ɵ�Ӱ�ȫ
{
	sort(records, records + k, cmp);
	ofstream outfile;
	outfile.open("database.dat", ios::out);
	outfile.close();
	for (int x = 0; x < k; x++)
	{
		records[x].save_to_file();
	}
	init();
}
void activity_edit(int n)//ɵ�Ӱ�ȫ
{
	string op;
	system("cls");
	records[n].show(n);
	cout << "\n��ѡ����Ҫ�޸ĵ���Ŀ\n";
	cout << "1.¥������\n2.ԤԼʱ��\n3.ά������\n4.�շ���ɱ�\n5.������\n6.��ע\n7.ȫ��\n8.�˳�\n";
	cout << "��һ������������Ҫ�޸ĵ���Ŀ���硰135��\n";
	cin >> op;
	for (int x = 0; x < op.length(); x++)
	{
		system("cls");
		records[n].show(n);
		switch (op[x])
		{
		case '1':edit_num(n); break;
		case '2':edit_date(n);break;
		case '3':edit_detail(n); break;
		case '4':edit_money(n); break;
		case '5':edit_people(n); break;
		case '6':edit_remark(n); break;
		case '7':edit_all(n); break;
		}
	}
	system("cls");
	records[n].show(n);
	save_all();
	cout << "�����ɹ����\n";
	system("pause");
}
void activity_delete(int n)//ɵ�Ӱ�ȫ
{
	cout << "������������棬ȷ��ɾ��������¼��(y/n)\n";
	char yesno;
	cin >> yesno;
	if (yesno != 'y')
		cout << "������ȡ��\n";
	else
	{
		for (int x = n; x < k - 1; x++)
		{
			records[x] = records[x + 1]; //δ������������ʵ��
		}
		k--;
		save_all();
		cout << "�����ѳɹ����\n";
		system("pause");
	}
}
void activity_finish(int n)//ɵ�Ӱ�ȫ
{
	char c;
	string day_later;
	date date_tmp = today();
	cout << "�������µ�ԤԼʱ��:������һ��С��10����n����ʾn���";
	cin >> day_later;
	while (!is_num(day_later))
	{
		cout << "������������������";
		cin.ignore(100, '\n');//���cin��
		cin >> day_later;
	}
	if (to_int(day_later) < 10)
	{
		for (int x = 0; x < to_int(day_later); x++)
		{
			date_tmp = date_tmp.tomorrow();
		}
	}
	else
	{
		int year = to_int(day_later);
		string month, day;
		cin >> month;
		while (!is_num(month))
		{
			cout << "�·�������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> month;
		}
		cin >> day;
		while (!is_num(day))
		{
			cout << "����������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> day;
		}
		date_tmp = date(year, to_int(month), to_int(day));
	}
	cout << "ȷ����ɲ����ˣ�(y/n)  ";
	cin >> c;
	if (c == 'y')
	{
		records[n].edit_date_fact(date_tmp);
		records[n].edit_done();
	}
	save_all();
	system("cls");
	records[n].show(n);
	cout << "\n�����ѳɹ����\n";
	system("pause");
}
int operate() //����������//ɵ�Ӱ�ȫ
{
	int n;
	string n_to_judge;
	char t;
	cout << "��������Ҫ������ID������-1�˳�\n";
	cin >> n_to_judge;
	while (!is_num(n_to_judge))
	{
		cout << "����������������룺";
		cin >> n_to_judge;
	}
	n = to_int(n_to_judge);
	if (n == -1)
	{
		return 0;
	}
	if (n >= k || n < 0)
	{
		cout << "�������\n";
		system("pause");
		return 1;
	}
	cout << "1.ɾ����¼   2.�޸ļ�¼  3.�깤�Ǽ�\n";
	cout << "��������Ҫ���еĲ����� ";
	cin >> t;
	switch (t)
	{
	case '1':activity_delete(n); break;
	case '2':activity_edit(n); break;
	case '3':activity_finish(n); break;
	}
	return 0;
}
void new_record()//ɵ�Ӳ���ȫ
{
	system("cls");
	int num_building, num_house; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_income, money_outcome; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	cout << "������¥�źͷ���\n";
	cin >> num_building >> num_house;
	cout << "������ԤԼʱ�䣨����һ��С��10����n����ʾn���\n";
	int day_later;
	cin >> day_later;
	if (day_later < 10)
	{
		date date_tmp = today();
		for (int x = 0; x < day_later; x++)
		{
			date_tmp = date_tmp.tomorrow();
		}
		date_yy=date_tmp;
	}
	else
	{
		int year = day_later;
		int month, day;
		cin >> month >> day;
		date_yy=(date(year, month, day));
	}
	cout << "������ά������\n";
	cin >> detail;
	cout << "�������շ���ɱ���\n";
	cin >> money_income >> money_outcome;
	cout << "��������Ա:\n";
	cin >> people;
	cout << "�����뱸ע:\n";
	cin >> remark;
	record new_record(num_building, num_house, date_yy, date_fact, detail, money_income, money_outcome, people, remark);
	new_record.save_to_file();
	system("cls");
	cout << "����ɹ�!��¼���£�\n";
	new_record.show();
	init();
	system("pause");
}
void search_record()//ɵ�Ӱ�ȫ
{
	system("cls");
	string key;
	cout << "��������Ҫ���ҵĹؼ���\n";
	cin >> key;
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].exist(key))
		{
			records[x].show(x);
			n++;
			continue;
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "û�з���Ҫ��ļ�¼\n";
		system("pause");
	}
}
void find_all_record()//ɵ�Ӱ�ȫ
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		records[x].show(x);
		cout << '\n';
	}
	if (k != 0) 
		operate();
	else
	{
		cout << "û�з���Ҫ��ļ�¼\n";
		system("pause");
	}
}
void fix_unfinished()//ɵ�Ӱ�ȫ
{
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished())
		{
			n++;
			records[x].show(x);
			cout << '\n';
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "û�з���Ҫ��ļ�¼\n";
		system("pause");
	}
}
void fix_overdate()//ɵ�Ӱ�ȫ
{
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && records[x].overdate(today()))
		{
			records[x].show(x);
			cout << '\n';
			n++;
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "û�з���Ҫ��ļ�¼\n";
		system("pause");
	}
}
void fix_two_days()//ɵ�Ӱ�ȫ
{
	system("cls");
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && records[x].overdate(today().tomorrow().tomorrow().tomorrow()))
		{
			n++;
			records[x].show(x);
			cout << '\n';
		}
	}
	if (n != 0)
		operate();
	else
	{
		cout << "û�з���Ҫ��ļ�¼\n";
		system("pause");
	}
}
void intime_service()//ɵ�Ӳ���ȫ
{
	system("cls");
	cout << "1.��ʾ����δ��ɵ�ά��\n";
	cout << "2.��ʾ����δ��ɵ�ά��\n";
	cout << "3.��ʾ��������Ҫ��ɵ�ά��\n";
	cout << "��������Ҫ��ʾ������\n";
	int t;
	cin >> t;
	switch (t)
	{
	case 1:fix_unfinished(); break;
	case 2:fix_overdate(); break;
	case 3:fix_two_days(); break;
	}
}
void statistic_income_date()//ɵ�Ӳ���ȫ
{
	cout << "��������Ҫͳ�Ƶ����ڣ� ";
	date d;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> d;
	for (int x = 0; x < k; x++)
	{
		if (records[x].day_fact_is(d) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << "\n����һ����ܹ�������" << num << "��ά�ޣ��յ���" << total_income << "Ԫ����ӯ��" << total_income - total_outcome << "Ԫ\n";
	system("pause");
}
void statistic_income_building()//ɵ�Ӳ���ȫ
{
	cout << "��������Ҫͳ�Ƶ�¥�� ";
	int build;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> build;
	for (int x = 0; x < k; x++)
	{
		if (records[x].num_building_is(build) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << "\n���ⶰ¥���ܹ�������" << num << "��ά�ޣ��յ���" << total_income << "Ԫ����ӯ��" << total_income - total_outcome << "Ԫ\n";
	system("pause");
}
void statistic_income_people()//ɵ�Ӱ�ȫ
{
	cout << "��������Ҫͳ�Ƶļ���Ա������ ";
	string name;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> name;
	for (int x = 0; x < k; x++)
	{
		if (records[x].name_is(name) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << '\n' << name << "�ܹ�������" << num << "��ά�ޣ��յ���" << total_income << "Ԫ����ӯ��" << total_income - total_outcome << "Ԫ\n";
	system("pause");
}
void statistic_income()//ɵ�Ӳ���ȫ
{
	int n;
	cout << "1.����ͳ��\n";
	cout << "2.��¥ͳ��\n";
	cout << "3.������Աͳ��\n";
	cout << "��ѡ��ͳ�Ƶ�ά�ȣ� ";
	cin >> n;
	switch (n)
	{
	case 1: statistic_income_date(); break;
	case 2: statistic_income_building(); break;
	case 3: statistic_income_people(); break;
	}
}
int main()//ɵ�Ӳ���ȫ
{
	init();
	cout << "��ӭʹ����ҵ����ά��ϵͳ\n";
	while (true)
	{
		int c;
		save_all();
		init();
		now().show();
		cout << '\n';
		cout << "����������������������������������������\n";
		cout << "�� 1.������¼       ��\n";
		cout << "�� 2.������¼       ��\n";
		cout << "�� 3.�鿴���м�¼   ��\n";
		cout << "�� 4.ԤԼ���ڲ�ѯ   ��\n";
		cout << "�� 5.�߼�ͳ�ƹ���   ��\n";
		cout << "�� 6.�˳�ϵͳ       ��\n";
		cout << "����������������������������������������\n";
		cout << "��������Ҫʹ�õĹ��ܣ� ";
		cin >> c;
		switch (c) {
		case 1:new_record(); break;
		case 2:search_record(); break;
		case 3:find_all_record(); break;
		case 4:intime_service(); break;
		case 5:statistic_income(); break;
		case 6:save_all(); cout << "�ټ�"; return 0; break;
		default:
			cout << "�����������������\n";
		}
		system("cls");
	}
}