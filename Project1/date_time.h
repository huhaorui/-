#pragma once
#include "date.h"
class date_time :public date
{
private:
	int hour;
	int minute;
	int second;
public:
	date_time(date d = date(2000, 1, 1), int h = 0, int m = 0, int s = 0);
	void show();
	~date_time();
};

