#include <iostream>
using namespace std;

int main()
{
	int n, x, y;
	unsigned long long f[1000] = {0};
	cin >> n >> x >> y;
	f[0] = 1;
	if (x != y)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i - x >= 0) f[i] += f[i - x];
			if (i - y >= 0) f[i] += f[i - y];
		}
	}
	else
	{
		if (n % x == 0) f[n] = 1;
	}
	if (f[n] > 0)
	{
		cout << f[n] << endl;
	}
	else
	{
		cout << "sorry" << endl;
	}
	return 0;
}