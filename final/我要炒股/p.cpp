#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
 
int main()
{
    //ifstream cin("stock.in");
    //ofstream cout("stock.out");
    int n;
    long long price0, price, gain = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        price0 = price;
        cin >> price;
        
        if (i > 0 && price > price0) // up
        {
            gain += price - price0;
        }
    }
    
    cout << gain << endl;
    
	return 0;
}