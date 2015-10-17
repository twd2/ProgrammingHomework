#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> digits;
	int a;
	for (int i = 0; i < 3; ++i)
	{
		cin >> a;
		digits.push_back(a);
	}
	
	sort(digits.begin(), digits.end());
	
	do
	{
		cout << digits[0] << digits[1] << digits[2] << endl;
	} while(next_permutation(digits.begin(), digits.end()));
	return 0;
}