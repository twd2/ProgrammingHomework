#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int toInt(string s)
{
	stringstream ss;
	ss << s;
	int i;
	ss >> i;
	return i;
}

string toString(int i)
{
	stringstream ss;
	ss << i;
	string s;
	ss >> s;
	return s;
}


int main()
{
	int last = -1;
	int a, count = 0;
	cin >> a;
	
	while (last != a)
	{
		string strSmall = toString(a);
		sort(strSmall.begin(), strSmall.end());
		
		string strBig = strSmall;
		reverse(strBig.begin(), strBig.end());
		
		int big = toInt(strBig), small = toInt(strSmall);
		
		last = a;
		a = big - small;
		
		++count;
	}
	
	cout << a << " " << count - 1 << endl;
	return 0;
}