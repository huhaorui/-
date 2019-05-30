#include <iostream>
#include "record.h"
#include "date_time.h"
#include "node.h"
#include <cstdio>
#include <fstream>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <string>
using namespace std;
#include "function.h"
void pause()
{
	system("pause");
}
void cls()
{
	system("cls");
}
date today()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	return d;
}
bool is_proper_num(char c)
{
	if (c <= '9' && c >= '0')
		return true;
	else
		return false;
}
bool is_proper_num(string s)
{
	if (s.length() > 8) return false;
	if (!is_proper_num(s[0]) && s[0] != '-') return false;
	for (int x = 1; x < s.length(); x++)
	{
		if (!is_proper_num(s[x]) && s[x] != '.') return false;
	}
	return true;
}
int to_int(string s)
{
	int n;
	stringstream sstr;
	sstr << s;
	sstr >> n;
	return n;
}
double to_double(string s)
{
	double n;
	stringstream sstr;
	sstr << s;
	sstr >> n;
	return n;
}
date_time now()
{
	tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	date d(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	date_time dt(d, t.tm_hour, t.tm_min, t.tm_sec);
	return dt;
}
string toString(int n)
{
	stringstream sstr;
	sstr << n;
	string str = sstr.str();
	return str;
}
string toString(double n)
{
	stringstream sstr;
	sstr << n;
	string str = sstr.str();
	return str;
}
