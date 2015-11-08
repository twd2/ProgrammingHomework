#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n, a[10050], b[10050], ab[100050], count = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		for (int j = 0; j < b[i]; ++j)
		{
			ab[count++] = a[i];
		}
	}
	
	sort(ab, ab + count);
	
	int minX = ab[count / 2];
	
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
