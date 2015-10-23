# 打印一个年历

## 题目描述
打印一年的年历

## 输入描述
一个数y（0<y<10000），表示年号

## 输出描述
y年的日历

## 样例输入
	2014

## 样例输出
	2014
	Jan
	MON TUE WED THU FRI SAT SUN
	          1   2   3   4   5
	  6   7   8   9  10  11  12
	 13  14  15  16  17  18  19
	 20  21  22  23  24  25  26
	 27  28  29  30  31
	Feb
	MON TUE WED THU FRI SAT SUN
	                      1   2
	  3   4   5   6   7   8   9
	 10  11  12  13  14  15  16
	 17  18  19  20  21  22  23
	 24  25  26  27  28
	Mar
	MON TUE WED THU FRI SAT SUN
	                      1   2
	  3   4   5   6   7   8   9
	 10  11  12  13  14  15  16
	 17  18  19  20  21  22  23
	 24  25  26  27  28  29  30
	 31
	Apr
	MON TUE WED THU FRI SAT SUN
	      1   2   3   4   5   6
	  7   8   9  10  11  12  13
	 14  15  16  17  18  19  20
	 21  22  23  24  25  26  27
	 28  29  30
	May
	MON TUE WED THU FRI SAT SUN
	              1   2   3   4
	  5   6   7   8   9  10  11
	 12  13  14  15  16  17  18
	 19  20  21  22  23  24  25
	 26  27  28  29  30  31
	Jun
	MON TUE WED THU FRI SAT SUN
	                          1
	  2   3   4   5   6   7   8
	  9  10  11  12  13  14  15
	 16  17  18  19  20  21  22
	 23  24  25  26  27  28  29
	 30
	Jul
	MON TUE WED THU FRI SAT SUN
	      1   2   3   4   5   6
	  7   8   9  10  11  12  13
	 14  15  16  17  18  19  20
	 21  22  23  24  25  26  27
	 28  29  30  31
	Aug
	MON TUE WED THU FRI SAT SUN
	                  1   2   3
	  4   5   6   7   8   9  10
	 11  12  13  14  15  16  17
	 18  19  20  21  22  23  24
	 25  26  27  28  29  30  31
	Sep
	MON TUE WED THU FRI SAT SUN
	  1   2   3   4   5   6   7
	  8   9  10  11  12  13  14
	 15  16  17  18  19  20  21
	 22  23  24  25  26  27  28
	 29  30
	Oct
	MON TUE WED THU FRI SAT SUN
	          1   2   3   4   5
	  6   7   8   9  10  11  12
	 13  14  15  16  17  18  19
	 20  21  22  23  24  25  26
	 27  28  29  30  31
	Nov
	MON TUE WED THU FRI SAT SUN
	                      1   2
	  3   4   5   6   7   8   9
	 10  11  12  13  14  15  16
	 17  18  19  20  21  22  23
	 24  25  26  27  28  29  30
	Dec
	MON TUE WED THU FRI SAT SUN
	  1   2   3   4   5   6   7
	  8   9  10  11  12  13  14
	 15  16  17  18  19  20  21
	 22  23  24  25  26  27  28
	 29  30  31

## 注释
输出需严格按照样例给出的格式，行尾不要有多余的空格。
本题为代码填充题，要求补全函数的内容，完成题目所述的输出。
建议调用程序中已有的函数，使得程序更加简单。

## 参考源程序 - C++

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
	 
	int is366(int y) {
		return ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)));
	}
	 
	const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int howManyDaysThisMonth(int y, int m) {
		if (m == 2)
			return (is366(y)? 29 : 28);
		else
			return month[m];
	}
	 
	int count(int y, int m, int d) {
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
	 
	int whatDayIsToday(int y, int m, int d) {
		int a1 = count(2014, 10, 27);
		int a2 = count(y, m, d);
		int ans = (1 + a2 - a1) % 7;
		if (ans <= 0)
			ans += 7;
		return ans;
	}
	 
	// 自己可以编写一些函数用于调用
	 
	void printMonth(int y, int m) { // 输出y年m月的月历
	 
	 
	}
	 
	void printYear(int y) { // 输出y年的年历
	 
	 
	}
	 
	int main() {
		int y;
		cin >> y;
		printYear(y);
	}