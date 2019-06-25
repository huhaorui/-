#pragma once
#include <iostream>
using namespace std;
class date
{
protected:
	int day, month, year;
public:
	date(int y = 1900, int m = 1, int d = 1);
	void show()
	{
		cout << year << '/' << month << '/' << day;
	}
	string out();
	date tomorrow();
	friend bool operator >(date& d1, date& d2);
	friend bool operator <(date& d1, date& d2);
	friend bool operator ==(date& d1, date& d2);
	friend ostream& operator <<(ostream& output, date& d);
	friend istream& operator >>(istream& input, date& d);
};