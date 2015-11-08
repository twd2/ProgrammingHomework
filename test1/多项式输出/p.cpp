#include <iostream>
using namespace std;
 
int main()
{
	int n, m;
	int a[100] = {0};
	cin >> n >> m;
	for (int i = n; i >= 0; --i)
	{
		cin >> a[i];
	}
	
	//y'
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			a[i] = (i + 1) * a[i + 1];
		}
		--n;
	}
	
	for (int i = n; i >= 0; --i)
	{
        if (n != 0 && a[i] == 0) continue;
		if (i > 0)
		{
			if (a[i] > 0)
			{
				if(i != n) cout << "+";
				if (a[i] != 1) cout << a[i];
			}
			else if (a[i] == -1) cout << "-";
			else cout << a[i];
			if (i > 1)
				cout << "x^" << i;
			else
				cout << "x";
		}
		else
		{
			if (a[i] > 0 && i != n)
			{
				cout << "+";
			}
			cout << a[i];
		}
	}
	
	if (n < 0) cout << 0;
	
	cout << endl;
	
	return 0;
}