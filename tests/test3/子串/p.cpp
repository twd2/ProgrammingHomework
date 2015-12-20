#include <iostream>
#include <string>>
using namespace std;

int main()
{
	bool found = true;
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); ++i)
	{
		if (s.length() % i != 0) continue;
		found = true;
		string subs = s.substr(0, i);
		for (int j = 1; j < s.length() / i; ++j)
		{
			string subs1 = s.substr(i * j, i);
			if (subs != subs1) 
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}
