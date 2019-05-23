#include "date_time.h"


void date_time::show()
{
	cout << "ÏÖÔÚÊÇ ";
	date::show();
	cout << " " << hour << ":" << minute << ":" << second << "\n";
}
date_time::date_time(date d, int h, int m, int s):date(d),hour(h),minute(m),second(s)
{}


date_time::~date_time()
{
}
