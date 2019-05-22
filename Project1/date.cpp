#include "date.h"


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



