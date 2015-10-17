#include <iostream>
using namespace std;

#define CALC(n) ((n) * ((n) + 1) / 2)
#define SIZE_OF_TABLE 5000

int findSum(int sum, int left, int right)
{
	int middle = (left + right) / 2;
	int a, b;
	a = CALC(middle);
	b = CALC(middle + 1);
	if (sum >= a && sum < b)
		return middle;
	else if (sum < a)
		return findSum(sum, left, middle - 1);
	else
		return findSum(sum, middle + 1, right);
}

int main()
{
	int count;
	cin >> count;
	while (count--)
	{
		int sum, n, delta;
		cin >> sum;
		n = findSum(sum, 0, SIZE_OF_TABLE);
		delta = sum - CALC(n);
		int r, c;
		if ((n & 1) == 0) // n % 2 == 0
		{
			r = n;
			c = 1;
			if (delta != 0)
			{
				r += 1 - delta + 1;
				c += delta - 1;
			}
		}
		else
		{
			r = 1;
			c = n;
			if (delta != 0)
			{
				c += 1 - delta + 1;
				r += delta - 1;
			}
		}
		cout << r << "/" << c << endl;
	}
	return 0;
}