#include <iostream>
using namespace std;

int digitSum(int a)
{
	int sum = 0;
	while (a > 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

#define GET_DIGIT(a, n) (((a) / pow10[(n)]) % 10)

bool check(int a)
{
	int length = (a >= 100000 ? 6 : 5);
	int last = length / 2;
	for (int i = 0; i < last; ++i)
	{
		if (GET_DIGIT(a, i) != GET_DIGIT(a, length - i - 1)) return false;
	}
	return true;
}

bool checkSpecial(int a, int sum)
{
	return check(a) && digitSum(a) == sum;
}

int main()
{
	int sum;
	cin >> sum;
	
	for (int i = 10001; i<= 999999; ++i)
	{
		if (checkSpecial(i, sum))
		{
			cout << i << endl;
		}
	}
	return 0;
}