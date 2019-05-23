#pragma once
#include "date.h"
class date_time:public date
{
private:
	int hour;
	int minute;
	int second;
public:
	date_time(int h = 0, int m = 0, int s = 0);
	~date_time();
};

