#include <iostream>
using namespace std;

#define MOD 10003

int main()
{
	int n, m, w, f[1050], h[1050], a[1050], b[1050];
	cin >> n >> m >> w;
	
	for (int i = 0; i < w; ++i)
	{
		cin >> h[i];
	}
	
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i] >> b[i];
	}
	
	f[1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		//floor
		for (int j = 0; j < m; ++j)
		{
			if (a[j] == i)
			{
				//go to floor b
				f[b[j]] = (f[b[j]] + f[i]) % MOD;
			}
		}
		//lift
		for (int j = 0; j < w; ++j)
		{
			f[i + h[j]] = (f[i + h[j]] + f[i]) % MOD;
		}
	}
	
	cout << f[n] << endl;
	
	return 0;
}