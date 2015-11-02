#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int n, a[10050], b[10050], maxX = 0;
	double minD = 10000.0 * 1000000.0 * 10.0;
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
	
	for (int x = 0; x < maxX; ++x)
	{
		double D = 0.0;
		for (int i = 0; i < n; ++i)
		{
			D += fabs(a[i] - x) * b[i];
		}
		//cout << D << endl;
		if (D < minD) 
		{
			minD = D;
			minX = x;
		}
	}
	
	const int mod = 10007;
	long long longD = 0;
	
	for (int i = 0; i < n; ++i)
	{
		longD += ((abs(a[i] - minX) % mod) * (b[i] % mod)) % mod;
		longD %= mod;
	}
	cout << minX << " " << longD << endl;
	return 0;
}