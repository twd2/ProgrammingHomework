#include <iostream>
using namespace std;
 
#define MOD 1000000007

long long f[1000000];

int main()
{
	int n;
	long long fac = 1, c = 1;
	f[1] = 0;
	
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		f[i] = (((i * f[i - 1]) % MOD) + c) % MOD;
		while (f[i] < 0) f[i] += MOD;
		c = -c;
		//cout << i << " " << f[i] << endl;
	}
	cout << f[n] % MOD << endl;
	return 0;
}