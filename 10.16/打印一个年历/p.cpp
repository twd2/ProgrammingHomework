#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
// 月份缩写数组
const char *words[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
 
// 可以调用的函数
int howManyDaysThisMonth(int y, int m); // 计算y年m月有多少天，返回天数
int whatDayIsToday(int y, int m, int d); // 计算y年m月d日是星期几，返回1-7
 
// 需要实现的函数
void printMonth(int y, int m); // 输出y年m月的月历
void printYear(int y); // 输出y年的年历
 
int is366(int y)
{
	return ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)));
}
 
const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int howManyDaysThisMonth(int y, int m)
{
	if (m == 2)
		return (is366(y)? 29 : 28);
	else
		return month[m];
}
 
int count(int y, int m, int d)
{
	int s = 0;
	int i;
	for (i = 0; i < y; i ++)
		s += is366(i)? 366 : 365;
	for (i = 1; i < m; i ++) {
		s += month[i];
		if (i == 2 && is366(y))
			s ++;
	}
	s += d;
	return s;
}
 
int whatDayIsToday(int y, int m, int d)
{
	int a1 = count(2014, 10, 27);
	int a2 = count(y, m, d);
	int ans = (1 + a2 - a1) % 7;
	if (ans <= 0)
		ans += 7;
	return ans;
}
 
// 自己可以编写一些函数用于调用
int intCeil(int a, int b)
{
	if (a % b == 0) return a / b;
	else return a / b + 1;
}
 
void printMonth(int y, int m)
{ // 输出y年m月的月历
	printf("%s\n", words[m]);
	
	int days = howManyDaysThisMonth(y, m);
	int firstDay = whatDayIsToday(y, m, 1);
	int rows = intCeil(days + firstDay - 1, 7);
	
	cout << "MON TUE WED THU FRI SAT SUN" << endl;
	for (int row = 0; row < rows; ++row)
	{
		for (int day = 1; day <= 7; ++day)
		{
			int number = (row * 7 + day) - firstDay + 1;
			if (number > 0 && number <= days)
			{
				printf("%3d", number);
			}
			else
			{
				printf("   ");
			}
			
			if (day != 7) printf(" ");
		}
		printf("\n");
	} 
}
 
void printYear(int y)
{ // 输出y年的年历
 	printf("%d\n", y);
	 
	for (int m = 1; m <= 12; ++m)
	{
		printMonth(y, m);
	}
}
 
int main()
{
	int y;
	cin >> y;
	printYear(y);
}