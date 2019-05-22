#include "date.h"


date::date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
ostream& operator <<(ostream& output, date& d)
{
	output << d.year << " " << d.month << " " << d.day << " ";
	return output;
}



