#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string str[50];
int used[50] = {0};
int same[50][50] ={{0}};
int n;
int maxDragonLength = 0;

int sameLength(string a, string b)
{
	int maxSame = 0;
	for (int i = a.length() - 1; i > 0; --i)
	{
		bool same = true;
		for (int j = 0; j < a.length() - i; ++j)
		{
			if (j >= b.length() || a[i + j] != b[j]) 
			{
				same = false;
				break;
			}
		}
		if (same) maxSame = a.length() - i;
	}
	return maxSame;
}

void foo(int lastStrIndex, int dragonLength)
{
	//cout << dragonLength << " " << lastStrIndex << endl;
	bool found = false;
	for (int i = 0; i < n; ++i)
	{
		if (used[i] < 2 &&
			same[lastStrIndex][i] > 0 &&
			same[lastStrIndex][i] < str[lastStrIndex].length() &&
			same[lastStrIndex][i] < str[i].length())
		{
			++used[i];
			foo(i, dragonLength + str[i].length() - same[lastStrIndex][i]);
			--used[i];
			found = true;
		}
	}
	
	if (!found)
	{
		//reach the dragon's tail
		if (dragonLength > maxDragonLength)
			maxDragonLength = dragonLength;
	}
}

int main()
{
	ifstream fin("dragon.in");
	ofstream fout("dragon.out");
	
	fin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		fin >> str[i];
	}
	
	char start;
	fin >> start;
	
	//cache
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			same[i][j] = sameLength(str[i], str[j]);
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (str[i][0] == start)
		{
			++used[i];
			foo(i, str[i].length());
			--used[i];
		}
	}
	
	fout << maxDragonLength << endl;
	return 0;
}