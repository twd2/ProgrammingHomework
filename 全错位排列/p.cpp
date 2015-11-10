#include <iostream>
using namespace std;

#define MOD 1000000007

int main()
{
	int n;
	long long f[1000000], fac = 1;
	f[1] = 0;
	
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		fac = (fac * i) % MOD;
		f[i] = (fac - ((i * f[i - 1]) % MOD) - 1) % MOD;
		cout << i << " " << f[i] << endl;
	}
	
	cout << (MOD + f[n]) % MOD << endl;
	return 0;
}