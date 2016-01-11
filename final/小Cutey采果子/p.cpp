#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n, a[50050], f[50050], p, q;
    cin >> n >> p >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i)
    {
        bool reached = false;
        f[i] = a[i];
        if (a[i] < 0) continue;
        if (i - p >= 0 && f[i - p] > 0)
        {
            f[i] = max(f[i - p] + a[i], f[i]);
            reached = true;
        }
        if (i - q >= 0 && f[i - q] > 0)
        {
            f[i] = max(f[i - q] + a[i], f[i]);
            reached = true;
        }
        if (i > 0 && !reached)
        {
            f[i] = -1;
        }
        
        //cout << i << ": " << f[i] << endl;
    }
    
    cout << f[n - 1] << endl;
    
	return 0;
}