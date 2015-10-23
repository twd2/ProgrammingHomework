#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> digits;
	for (int i = 1; i <= n; ++i)
	{
		digits.push_back(i);
	}
	do 
	{
		for (int i = 0; i < n; ++i)
		{
			cout << digits[i];
			if (i < n - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	} while (next_permutation(digits.begin(), digits.end()));
	return 0;
}