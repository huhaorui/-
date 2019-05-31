#include <iostream>
#include "record.h"
#include "date_time.h"
#include "node.h"
#include "function.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <time.h>
using namespace std;
record records[100000];
int k = 0;//�ܵļ�¼��
//ɵ�Ӱ�ȫ�Ķ��壺cin��ֻ�����string�У����������Ҫ�󣬾ͻ�Ҫ������

void edit_num(int n)//ɵ�Ӱ�ȫ
{
	string num_building, num_house;
	cout << "�������µ�¥���뷿��:";
	cin >> num_building;
	while (!is_proper_num(num_building))
	{
		cout << "¥��������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> num_building;
	}
	cin >> num_house;
	while (!is_proper_num(num_house))
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
	while (!is_proper_num(day_later))
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
		records[n].edit_date_reserve(date_tmp);
	}
	else
	{
		int year = to_int(day_later);
		string month, day;
		cin >> month;
		while (!is_proper_num(month))
		{
			cout << "�·�������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> month;
		}
		cin >> day;
		while (!is_proper_num(day))
		{
			cout << "����������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> day;
		}
		records[n].edit_date_reserve(date(year, to_int(month), to_int(day)));
	}
}
void edit_content(int n)//ɵ�Ӱ�ȫ
{
	string content;
	cout << "������ά�����ݣ� ";
	cin >> content;
	records[n].edit_content(content);
}
void edit_money(int n)//ɵ�Ӱ�ȫ
{
	string money_income, money_outcome;
	cout << "�������շѺͳɱ��� ";
	cin >> money_income;
	while (!is_proper_num(money_income))
	{
		cout << "�շ�������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> money_income;
	}
	cin >> money_outcome;
	while (!is_proper_num(money_outcome))
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
	edit_content(n);
	edit_money(n);
	edit_people(n);
	edit_remark(n);
}
void init()//ɵ�Ӱ�ȫ
{
	k = 0;
	int num_building, num_house; //¥�ţ�����
	date date_reserve, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string content; //ά������
	double money_income, money_outcome; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	int done;
	ifstream infile;
	infile.open("database.dat", ios::in);
	while (infile >> num_building >> num_house >> date_reserve >> date_fact >> content >> money_income >> money_outcome >> people >> remark >> done)
	{
		records[k].set(num_building, num_house, date_reserve, date_fact, content, money_income, money_outcome, people, remark, done);
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
	cout << "���ڱ����ļ��������ĵȴ�\n";
	sort(records, records + k, cmp);
	ofstream outfile;
	outfile.open("database.dat", ios::out);
	for (int x = 0; x < k; x++)
	{
		outfile << records[x].show_in_line();
	}
	outfile.close();
	init();
}
void activity_edit(int n)//ɵ�Ӱ�ȫ
{
	string op;
	cls();
	records[n].show(n);
	cout << "\n��ѡ����Ҫ�޸ĵ���Ŀ\n";
	cout << "1.¥������\n2.ԤԼʱ��\n3.ά������\n4.�շ���ɱ�\n5.������\n6.��ע\n7.ȫ��\n8.�˳�\n";
	cout << "��һ������������Ҫ�޸ĵ���Ŀ���硰135��\n";
	cin >> op;
	for (int x = 0; x < op.length(); x++)
	{
		cls();
		records[n].show(n);
		switch (op[x])
		{
		case '1':edit_num(n); break;
		case '2':edit_date(n); break;
		case '3':edit_content(n); break;
		case '4':edit_money(n); break;
		case '5':edit_people(n); break;
		case '6':edit_remark(n); break;
		case '7':edit_all(n); break;
		}
	}
	cls();
	records[n].show(n);
	save_all();
	cout << "�����ɹ����\n";
	pause();
}
void activity_delete(int n)//ɵ�Ӱ�ȫ
{
	cout << "������������棬ȷ��ɾ��������¼��(y/n)\n";
	string yesno;
	cin >> yesno;
	if (yesno[0] != 'y')
	{
		cout << "������ȡ��\n";
		pause();
	}
	else
	{
		for (int x = n; x < k - 1; x++)
		{
			records[x] = records[x + 1]; //δ������������ʵ��
		}
		k--;
		save_all();
		cout << "�����ѳɹ����\n";
		pause();
	}
}
void activity_finish(int n)//ɵ�Ӱ�ȫ
{
	string day_later;
	date date_tmp = today();
	cout << "������ʱ��:������һ��С��10����n����ʾn���";
	cin >> day_later;
	while (!is_proper_num(day_later))
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
		while (!is_proper_num(month))
		{
			cout << "�·�������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> month;
		}
		cin >> day;
		while (!is_proper_num(day))
		{
			cout << "����������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> day;
		}
		date_tmp = date(year, to_int(month), to_int(day));
	}
	string c;
	cout << "ȷ����ɲ����ˣ�(y/n)  ";
	cin >> c;
	if (c[0] == 'y')
	{
		records[n].edit_date_fact(date_tmp);
		records[n].edit_done();
	}
	save_all();
	cls();
	records[n].show(n);
	cout << "\n�����ѳɹ����\n";
	pause();
}
int operate() //����������//ɵ�Ӱ�ȫ
{
	int n;
	string n_to_judge;
	string t;
	cout << "��������Ҫ������ID������-1�˳�\n";
	cin >> n_to_judge;
	while (!is_proper_num(n_to_judge))
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
		pause();
		return 1;
	}
	cout << "1.ɾ����¼   2.�޸ļ�¼  3.�깤�Ǽ�\n";
	cout << "��������Ҫ���еĲ����� ";
	cin >> t;
	switch (t[0])
	{
	case '1':activity_delete(n); break;
	case '2':activity_edit(n); break;
	case '3':activity_finish(n); break;
	}
	return 0;
}
void new_record()//ɵ�Ӱ�ȫ
{
	cls();
	string num_building, num_house; //¥�ţ�����
	date date_reserve, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string content; //ά������
	string money_income, money_outcome; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	cout << "������¥�źͷ���\n";
	cin >> num_building;
	while (!is_proper_num(num_building))
	{
		cout << "¥��������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> num_building;
	}
	cin >> num_house;
	while (!is_proper_num(num_house))
	{
		cout << "����������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> num_house;
	}
	string day_later;
	cout << "������ԤԼʱ��:������һ��С��10����n����ʾn���";
	cin >> day_later;
	while (!is_proper_num(day_later))
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
		date_reserve = date_tmp;
	}
	else
	{
		int year = to_int(day_later);
		string month, day;
		cin >> month;
		while (!is_proper_num(month))
		{
			cout << "�·�������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> month;
		}
		cin >> day;
		while (!is_proper_num(day))
		{
			cout << "����������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> day;
		}
		date_reserve = date(year, to_int(month), to_int(day));
	}
	cout << "������ά������\n";
	cin >> content;
	cout << "�������շ���ɱ�\n";
	cin >> money_income;
	while (!is_proper_num(money_income))
	{
		cout << "�շ�������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> money_income;
	}
	cin >> money_outcome;
	while (!is_proper_num(money_outcome))
	{
		cout << "�ɱ�������������������:";
		cin.ignore(100, '\n');//���cin��
		cin >> money_outcome;
	}
	cout << "��������Ա:\n";
	cin >> people;
	cout << "�����뱸ע:\n";
	cin >> remark;
	records[k] = record(to_int(num_building), to_int(num_house), date_reserve, date_fact, content, to_double(money_income), to_double(money_outcome), people, remark);
	cls();
	cout << "����ɹ�!��¼���£�\n";
	records[k].show();
	k++;
	save_all();
	init();
	pause();
}
void search_record()//ɵ�Ӱ�ȫ
{
	cls();
	string key;
	cout << "��������Ҫ���ҵĹؼ��ʣ�ϵͳ���Զ�����ȫ��ƥ��\n";
	cin >> key;
	cls();
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
		pause();
	}
}
void find_all_record()//ɵ�Ӱ�ȫ
{
	cls();
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
		pause();
	}
}
void fix_unfinished()//ɵ�Ӱ�ȫ
{
	cls();
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
		pause();
	}
}
void fix_overdate()//ɵ�Ӱ�ȫ
{
	cls();
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
		pause();
	}
}
void fix_two_days()//ɵ�Ӱ�ȫ
{
	cls();
	int n = 0;
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && !records[x].overdate(today()) && records[x].overdate(today().tomorrow().tomorrow().tomorrow()))
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
		pause();
	}
}
void intime_service()//ɵ�Ӱ�ȫ
{
	cls();
	cout << "1.��ʾ����δ��ɵ�ά��\n";
	cout << "2.��ʾ����δ��ɵ�ά��\n";
	cout << "3.��ʾ��������Ҫ��ɵ�ά��\n";
	cout << "��������Ҫ��ʾ������\n";
	string t_todo;
	cin >> t_todo;
	char t = t_todo[0];
	switch (t)
	{
	case '1':fix_unfinished(); break;
	case '2':fix_overdate(); break;
	case '3':fix_two_days(); break;
	}
}
void statistic_income_date()//ɵ�Ӱ�ȫ
{
	cout << "��������Ҫͳ�Ƶ����ڣ�����0ͳ�ƽ��죺";
	date d;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	string day_later;
	cin >> day_later;
	while (!is_proper_num(day_later))
	{
		cout << "������������������";
		cin.ignore(100, '\n');//���cin��
		cin >> day_later;
	}
	if (to_int(day_later) == 0)
		d = today();
	else
	{
		int year = to_int(day_later);
		string month, day;
		cin >> month;
		while (!is_proper_num(month))
		{
			cout << "�·�������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> month;
		}
		cin >> day;
		while (!is_proper_num(day))
		{
			cout << "����������������������:";
			cin.ignore(100, '\n');//���cin��
			cin >> day;
		}
		d = date(year, to_int(month), to_int(day));
	}
	for (int x = 0; x < k; x++)
	{
		if (records[x].day_fact_is(d) && !records[x].unfinished())
		{
			num++;
			total_income += records[x].get_income();
			total_outcome += records[x].get_outcome();
		}
	}
	cout << "\n��";
	d.show();
	cout << "���ܹ�������" << num << "��ά�ޣ��յ���" << total_income << "Ԫ����ӯ��" << total_income - total_outcome << "Ԫ\n";
	pause();
}
void statistic_income_building()//ɵ�Ӱ�ȫ
{
	cout << "��������Ҫͳ�Ƶ�¥�� ";
	string build_to_judge;
	double total_income = 0, total_outcome = 0;
	int num = 0;
	cin >> build_to_judge;
	while (!is_proper_num(build_to_judge))
	{
		cout << "�������������:";
		cin >> build_to_judge;
	}
	int build = to_int(build_to_judge);
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
	pause();
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
	pause();
}
void statistic_income()//ɵ�Ӱ�ȫ
{
	string n;
	cout << "1.����ͳ��\n";
	cout << "2.��¥ͳ��\n";
	cout << "3.������Աͳ��\n";
	cout << "��ѡ��ͳ�Ƶ�ά�ȣ� ";
	cin >> n;
	switch (n[0])
	{
	case '1': statistic_income_date(); break;
	case '2': statistic_income_building(); break;
	case '3': statistic_income_people(); break;
	}
}
void random_record()
{
	cls();
	for (int x=0;x<100;x++)
		srand(rand());
	Node* head = read_data_from_array(records, k);
	int t = float(rand()) / RAND_MAX * k;
	record random_record = get_node(head, t);
	random_record.show(t);
	operate();
}
int main()//ɵ�Ӱ�ȫ
{
	init();
	cout << "��ӭʹ����ҵά�޹���ϵͳ\n";
	while (true)
	{
		string c;
		cout << "���ڶ�ȡ�ļ�����ȴ�\n";
		init();
		cls();
		srand((int)time(0));
		now().show();
		cout << '\n';
		cout << "����������������������������������������\n";
		cout << "�� 1.������¼       ��\n";
		cout << "�� 2.������¼       ��\n";
		cout << "�� 3.�鿴���м�¼   ��\n";
		cout << "�� 4.ԤԼ���ڲ�ѯ   ��\n";
		cout << "�� 5.�߼�ͳ�ƹ���   ��\n";
		cout << "�� 6.��ʾ�����¼   ��\n";
		cout << "�� 7.�˳�ϵͳ       ��\n";
		cout << "����������������������������������������\n";
		cout << "��������Ҫʹ�õĹ��ܣ� ";
		cin >> c;
		switch (c[0] - '0') {
		case 1:new_record(); break;
		case 2:search_record(); break;
		case 3:find_all_record(); break;
		case 4:intime_service(); break;
		case 5:statistic_income(); break;
		case 6:random_record(); break;
		case 7:save_all(); cout << "��лʹ�ã��ټ�"; return 0; break;
		default:
			cout << "�����������������\n";
		}
		cls();
	}
}