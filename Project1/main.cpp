#include <iostream>
#include "record.h"
#include <cstdio>
#include <fstream>
using namespace std;
void new_record()
{
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
}
void search_record()
{

}
void find_all_record()
{

}
void intime_service()
{

}
void advanced_feature()
{

}
int main()
{
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