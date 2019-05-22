#include <iostream>
#include "record.h"
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <time.h>
using namespace std;
record records[1000];
int k=0;//�ܵļ�¼��
date today()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	return d;
}
void init()
{
	k = 0;
	int num_l, num_f; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_get, money_used; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	int done;
	ifstream infile;
	infile.open("datebase.dat", ios::in);
	while (infile >> num_l >> num_f >> date_yy >> date_fact >> detail >> money_get >> money_used >> people >> remark >> done)
	{
		records[k].set(num_l, num_f, date_yy, date_fact, detail, money_get, money_used, people, remark, done);
		k++;
	}
	infile.close();
}
void save_all()
{
	ofstream outfile;
	outfile.open("datebase.dat", ios::out);
	outfile.close();
	for (int x = 0; x < k; x++)
	{
		records[x].save_to_file();
	}
	init();
}
void activity_edit(int n)
{
	string op;
	system("cls");
	records[n].show();
	cout << "\n��ѡ����Ҫ�޸ĵ���Ŀ\n";
	cout << "1.¥������\n2.ԤԼʱ��\n3.ά������\n4.�շ���ɱ�\n5.������\n6.��ע\n7.ȫ��\n8.�˳�\n";
	cout << "��һ������������Ҫ�޸ĵ���Ŀ���硰135��\n";
	cin >> op;
	for (int x = 0; x < op.length(); x++)
	{
		int num_l, num_f; //¥�ţ�����
		date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
		string detail; //ά������
		double money_get, money_used; //�շѣ��ɱ�
		string people; //������
		string remark; //��ע	
		system("cls");
		records[n].show();
		switch (op[x])
		{
		case '1':
			cout << "�������µ�¥���뷿��:";
			cin >> num_l >> num_f;
			records[n].edit_num(num_l, num_f);
			break;
		case '2':
			cout << "�������µ�ԤԼʱ��:";
			cin >> date_yy;
			records[n].edit_date_yy(date_yy);
			break;
		case '3':
			cout << "������ά�����ݣ�";
			cin >> detail;
			records[n].edit_detail(detail);
			break;
		case '4':
			cout << "�������շѺͳɱ���";
			cin >> money_get >> money_used;
			records[n].edit_money(money_get, money_used);
			break;
		case '5':
			cout << "����������ˣ�";
			cin >> people;
			records[n].edit_people(people);
			break;
		case '6':
			cout << "�����뱸ע��";
			cin >> remark;
			records[n].edit_remark(remark);
			break;
		case '7':
			cout << "�������µ�¥���뷿��:";
			cin >> num_l >> num_f;
			records[n].edit_num(num_l, num_f);
			cout << "�������µ�ԤԼʱ��:";
			cin >> date_yy;
			records[n].edit_date_yy(date_yy);
			cout << "������ά�����ݣ�";
			cin >> detail;
			records[n].edit_detail(detail);
			cout << "�������շѺͳɱ���";
			cin >> money_get >> money_used;
			records[n].edit_money(money_get, money_used);
			cout << "����������ˣ�";
			cin >> people;
			records[n].edit_people(people);
			cout << "�����뱸ע��";
			cin >> remark;
			records[n].edit_remark(remark);
		case '8':
		default:;
		}
	}
	save_all();
	system("cls");
	cout << "�����ɹ����\n";
	records[n].show();
	system("pause");
}
void activity_delete(int n)
{
	cout << "������������棬ȷ��ɾ��������¼��(y/n)\n";
	char yesno;
	cin >> yesno;
	if (yesno != 'y')
		cout << "������ȡ��\n";
	else
		for (int x = n; x < k - 1; x++)
		{
			records[x] = records[x + 1]; //δ������������ʵ��
		}
	k--;
	save_all();
}
void activity_finish(int n)
{
	date d;
	char c;
	cout << "������������ڣ�";
	cin >> d;
	cout << "ȷ����ɲ����ˣ�(y/n)  ";
	cin >> c;
	if (c == 'y')
	{
		records[n].edit_date_fact(d);
		records[n].edit_done();
	}
	save_all();
	system("cls");
	records[n].show();
	cout << "\n�����ѳɹ����\n";
	system("pause");
}
int operate() //����������
{
	int n, t;
	cout << "��������Ҫ������ID������-1�˳�\n";
	cin >> n;
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
	cout << "��������Ҫ���еĲ�����";
	cin >> t;
	switch (t)
	{
	case 1:activity_delete(n); break;
	case 2:activity_edit(n); break;
	case 3:activity_finish(n); break;
	default:break;
	}
	return 0;
}
void new_record()
{
	system("cls");
	int num_l, num_f; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_get, money_used; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	cout << "������¥�źͷ���\n";
	cin >> num_l >> num_f;
	cout << "������ԤԼʱ��\n";
	cin >> date_yy;
	cout << "������ά������\n";
	cin >> detail;
	cout << "�������շ���ɱ���\n";
	cin >> money_get >> money_used;
	cout << "��������Ա:\n";
	cin >> people;
	cout << "�����뱸ע:\n";
	cin >> remark;
	record new_record(num_l, num_f, date_yy, date_fact, detail, money_get, money_used, people, remark);
	new_record.save_to_file();
	system("cls");
	cout << "����ɹ�!��¼���£�\n";
	new_record.show();
	init();
	system("pause");
}
void search_record()
{
	system("cls");
	string key;
	cout << "��������Ҫ���ҵĹؼ���\n";
	cin >> key;
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].exist(key))
		{
			cout << "ID\t��" << x << '\n';
			records[x].show();
			cout << '\n';
			continue;
		}
	}
	operate();
}
void find_all_record()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		cout << "ID\t��" << x << '\n';
		records[x].show();
		cout << '\n';
	}
	operate();
}
void fix_unfinished()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished())
		{
			cout << "ID\t��" << x << '\n';
			records[x].show();
			cout << '\n';
		}
	}
	operate();
}
void fix_overdate()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished()&&records[x].overdate(today()))
		{
			cout << "ID\t��" << x << '\n';
			records[x].show();
			cout << '\n';
		}
	}
	operate();
}
void fix_two_days()
{
	system("cls");
	for (int x = 0; x < k; x++)
	{
		if (records[x].unfinished() && records[x].overdate(today().tomorrow().tomorrow().tomorrow()))
		{
			cout << "ID\t��" << x << '\n';
			records[x].show();
			cout << '\n';
		}
	}
	operate();
}
void intime_service()
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
void advanced_feature()
{

}
int main()
{
	init();
	cout << "��ӭʹ����ҵ����ά��ϵͳ\n";
	while (true)
	{
		int c;
		cout << "1.������¼\n";
		cout << "2.������¼\n";
		cout << "3.�鿴���м�¼\n";
		cout << "4.ԤԼ���ڲ�ѯ\n";
		cout << "5.�߼�ͳ�ƹ���\n";
		cout << "6.�˳�ϵͳ\n";
		cout << "��������Ҫʹ�õĹ��ܣ�";
		cin >> c;
		switch (c){
		case 1:new_record(); break;
		case 2:search_record(); break;
		case 3:find_all_record(); break;
		case 4:intime_service(); break;
		case 5:advanced_feature(); break;
		case 6:save_all(); cout << "�ټ�"; return 0; break;
		default:
			cout << "�����������������\n";
		}
		system("cls");
	}
}