#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
struct I
{
	int l, r;
	
	bool check(int xi)
	{
		return xi >= l && xi <= r;
	}
};
 
int toInt(string s)
{
	stringstream ss;
	ss << s;
	int a;
	ss >> a;
	return a;
}
 
I parse(string s)
{
	I i;
	i.l = i.r = 0;
	
	if (s[0] == '(') i.l = 1;
	if (s[s.length() - 1] == ')') i.r = -1;
	
	int index = s.find(',');
	
	string strL = s.substr(1, index - 1);
	string strR = s.substr(index + 1, s.length() - index - 1 - 1);
	
	i.l += toInt(strL);
	i.r += toInt(strR);
	return i;
}
 
int main()
{
	I Ix[1000];
	int N, x;
	cin >> N >> x;
	
	int minXi = 0, maxXi = -1;
	string tmp;
	getline(cin, tmp);
	for (int i = 0; i < N; ++i)
	{
		getline(cin, tmp);
		Ix[i] = parse(tmp);
		if (i > 0)
		{
			if (minXi > Ix[i].l) minXi = Ix[i].l;
			if (maxXi < Ix[i].r) maxXi = Ix[i].r;
		}
		else
		{
			minXi = Ix[i].l;
			maxXi = Ix[i].r;
		}
	}
	
	if (minXi < 0) minXi = 0;
	if (maxXi > 1000000) maxXi = 1000000;
	
	for (int xi = minXi; xi <= maxXi; ++xi)
	{
		int trueCount = 0;
		for (int i = 0; i < N; ++i)
		{
			trueCount += (int)Ix[i].check(xi);
		}
		if (trueCount == x)
		{
			cout << xi << endl;
			break;
		}
	}
	return 0;
}
