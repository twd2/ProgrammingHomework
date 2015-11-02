#include <iostream>
using namespace std;

int main()
{
	int n, m, a[1050];
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	while (m --> 0)
	{
		int l, r, k, count = 0;
		cin >> l >> r >> k;
		--l;
		--r;
		for (int i = l; i <= r; ++i)
		{
			if (a[i] < k) ++count;
		}
		cout << count << endl;
	}
	return 0;
}