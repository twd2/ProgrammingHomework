#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toString(long long a)
{
	string s;
	stringstream ss;
	ss << a;
	ss >> s;
	return s;
}

int main()
{
	long long a;
	string s;
	cin >> a >> s;
	for (long long b = 1; ; ++b)
	{
		string c = toString(a * b);
		if (c.find(s) != string::npos)
		{
			cout << b << endl;
			break;
		}
	}
	return 0;
}