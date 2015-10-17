#include <iostream>
using namespace std;

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
	int year, m, d;
	cin >> year >> m >> d;
	
	if (m <= 2)
	{
		m += 12;
		--year;
	}
	int c = year / 100,
		y = year % 100;
	
	int day = intMod(c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1, 7);
	if (day == 0) day = 7;
	cout << day << endl;
	return 0;
}