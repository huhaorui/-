#include "date.h"
int day_of_month(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 29;
	else
		return 28;
}

date::date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
bool operator >(date& d1, date& d2)
{
	if (d1.year > d2.year)
		return true;
	else if (d1.year < d2.year)
		return false;
	else if (d1.month > d2.month)
		return true;
	else if (d1.month < d2.month)
		return false;
	else if (d1.day > d2.day)
		return true;
	else return false;
}
bool operator <(date& d1, date& d2)
{
	if (d1.year < d2.year)
		return true;
	else if (d1.year > d2.year)
		return false;
	else if (d1.month < d2.month)
		return true;
	else if (d1.month > d2.month)
		return false;
	else if (d1.day < d2.day)
		return true;
	else return false;
}
ostream& operator <<(ostream& output, date& d)
{
	output << d.year << " " << d.month << " " << d.day << " ";
	return output;
}
istream& operator >>(istream& input, date& d)
{
	input >> d.year >> d.month >> d.day;
	return input;
}
date date::tomorrow()
{
	date d1(year, month, day);
	d1.day++;
	if (d1.day > day_of_month(d1.year, d1.month))
	{
		d1.day -= day_of_month(d1.year, d1.month);
		d1.month++;
	}
	if (d1.month > 12)
	{
		d1.month = 1;
		d1.year++;
	}
	return d1;
}