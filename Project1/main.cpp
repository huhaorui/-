#include <iostream>
#include "record.h"
#include <cstdio>
#include <fstream>
#include <conio.h>
using namespace std;
record records[1000];
int k=0;
void init()
{
	k = 0;
	int num_l, num_f; //¥�ţ�����
	date date_yy, date_fact; //ԤԼʱ�䣬ʵ��ʱ��
	string detail; //ά������
	double money_get, money_used; //�շѣ��ɱ�
	string people; //������
	string remark; //��ע	
	ifstream infile;
	infile.open("datebase.dat", ios::in);
	while (infile >> num_l >> num_f >> date_yy >> date_fact >> detail >> money_get >> money_used >> people >> remark)
	{
		records[k].set(num_l, num_f, date_yy, date_fact, detail, money_get, money_used, people, remark);
		k++;
	}
	infile.close();
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
	system("pause");
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
	system("pause");
}
void intime_service()
{

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
		case 6:cout << "�ټ�"; return 0; break;
		default:
			cout << "�����������������\n";

		}
		system("cls");
	}
}