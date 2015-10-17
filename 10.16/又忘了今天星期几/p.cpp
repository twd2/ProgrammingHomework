#include <iostream>
using namespace std;

bool isLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

//                         1   2   3   4   5   6   7   8   9   10  11  12
int dayOfMonthData[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayOfMonth(int year, int month)
{
	if (month != 2) return dayOfMonthData[month];
	return dayOfMonthData[2] + (isLeap(year) ? 1 : 0);
}

int dayOfYear(int year)
{
	return 365 + (isLeap(year) ? 1 : 0);
}

int toUniform(int year, int month, int day) //days from 0000-01-01
{
	int totalDays = 0;
	
	for (int y = 0; y < year; ++y)
	{
		totalDays += dayOfYear(y);
	}
	
	for (int m = 1; m < month; ++m)
	{
		totalDays += dayOfMonth(year, m);
	}
	
	totalDays += day - 1;
	return totalDays;
}

int dateDiff(int year1, int month1, int day1, int year2, int month2, int day2)
{
	return toUniform(year2, month2, day2) - toUniform(year1, month1, day1);
}

int intMod(int a, int b)
{
	if (b < 0)
	{
		a = -a;
		b = -b;
	}
	if (a > 0)
	{
		return a % b;
	}
	else
	{
		int absA = -a;
		int add = absA + (b - (absA % b));
		return (add + a) % b;
	}
}

int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	
	int diff = dateDiff(2014, 10, 27, year, month, day); //2014-10-27 Mon.
	
	cout << 1 + intMod(diff, 7) << endl;
	return 0;
}