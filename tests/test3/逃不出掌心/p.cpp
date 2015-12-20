#include <iostream>
using namespace std;

int main()
{
	unsigned long long n;
	unsigned long long log[1000050];
	int logCount = 0;
	cin >> n;
	bool succ = false;
	for (int i = 0; i < 1000000; ++i)
	{
		log[logCount] = n;
		++logCount;
		if (n == 1)
		{
			succ = true;
			break;
		}
		if ((n & 1) == 0)
		{
			n /= 2;
		}
		else
		{
			n += 2 * n + 1;
		}
	}
	if (succ)
	{
		for (int i = 0; i < logCount; ++i)
		{
			cout << log[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Escaped!" << endl;
	}
	return 0;
}