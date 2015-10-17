#include <iostream>
using namespace std;

int countFactor(int a, int factor)
{
	int count = 0;
	while (a % factor == 0)
	{
		a /= factor;
		++count;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		count += countFactor(i, 5);
	}
	cout << count << endl;
	return 0;
}