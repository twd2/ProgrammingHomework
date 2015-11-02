#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int n, a[10050], b[10050], maxX = 0;
	long long minD = 10000L * 1000000 * 10;
	int minX = -1;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > maxX) maxX = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	
	for (int x = 0; x <= maxX; ++x)
	{
		long long D = 0;
		for (int i = 0; i < n; ++i)
		{
			D += abs(a[i] - x) * b[i];
		}
		//cout << D << endl;
		if (D < minD) 
		{
			minD = D;
			minX = x;
		}
	}
	
	const int mod = 10007;
	
	cout << minX << " " << minD % 10007 << endl;
	return 0;
}