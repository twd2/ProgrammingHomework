#include <iostream>
using namespace std;

int foo(long long x)
{
	//cout << x << endl;
	if (x < 0)
		return foo(-x);
	if (x == 1)
		return x;

	long long a = 1;
	int count = 1;
	for (; a < x;)
	{
		a *= 10;
		a += 1;
		++count;
	}

	if (x - (a / 10) <= a - x)
	{
		//cout << (a / 10) << endl;
		return foo(x - (a / 10)) + count - 1;
	}
	else
	{
		//cout << a << endl;
		return foo(a - x) + count;
	}
}

int main()
{
	long long x;
	cin >> x;
	int ans = foo(x);
	cout << ans << endl;
	return 0;
}