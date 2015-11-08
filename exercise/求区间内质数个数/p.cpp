#include <iostream>
#include <cmath>
using namespace std;

long long L, R;
bool isPrime[1000050];

void makeTable()
{
	for (long long i = 0; i <= R - L; ++i)
		isPrime[i] = true;
		
	long long sqrtR = sqrt(R);
	for (long long i = 2; i <= sqrtR; ++i)
	{
		long long start = L;
		if (L % i != 0)
		{
			start = ((L / i) + 1) * i; //大于L的最小的i的倍数
		}
		if (start < i << 1) start = i << 1; //start最小应该从i * 2开始
		
		for (long long j = start; j <= R; j += i)
		{
			isPrime[j - L] = false;
		}
	}
}

int main()
{ 
	cin >> L >> R;
	makeTable();
		
	long long count = 0;
	
	for (long long i = L; i <= R; ++i)
	{
		if (isPrime[i - L]) ++count;
	}
	cout << count << endl;
	return 0;
}