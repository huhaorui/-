#include <iostream>
using namespace std;
#pragma once
class date
{
private:
	int day, month, year;
public:
	date(int y = 2019, int m = 5, int d = 22);
	friend bool operator >(date& d1, date& d2);
	friend bool operator <(date& d1, date& d2);
	friend ostream& operator <<(ostream& output, date& d);
};

