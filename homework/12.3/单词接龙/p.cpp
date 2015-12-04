#define FILE_IO

#ifndef FILE_IO
#include <iostream>
#else
#include <fstream>
#endif 

#include <string>
#include <cstring>
using namespace std;

int n;
string str[50];
int same[50][50] = {{0}};
int cache[666666]; //>0: value, -1: no value, -2: cannot reach
int threePow[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147};

int sameLength(string a, string b)
{
	int result = 0;
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
		if (same) 
		{
			result =  a.length() - i;
			break; //we need a smaller result to make the dragon longer
		}
	}
	if (result == a.length() || result == b.length()) result = 0;
	return result;
}

int getId(int *used, int lastStrIndex)
{
	int id = 0;
	for (int i = 0; i < n; ++i)
	{
		id += used[i] * threePow[i];
	}
	id += lastStrIndex * threePow[n];
	return id;
}

void parseId(int id, int *used, int *outLastStrIndex)
{
	for (int i = 0; i < n; ++i)
	{
		used[i] = (id / threePow[i]) % 3;
	}
	*outLastStrIndex = id / threePow[n];
}

int search(int id)
{
	if (cache[id] != -1) return cache[id];
	
	//current state
	int used[50], lastStrIndex;
	parseId(id, used, &lastStrIndex);
	
	if (used[lastStrIndex] == 0)
	{
		//invalid state, cannot reach
		return cache[id] = -2;
	}
	
	//enum. last state
	for (int i = 0; i < n; ++i)
	{
		if (used[i] > 0 && same[i][lastStrIndex] > 0)
		{
			--used[lastStrIndex];
			int lastid = getId(used, i);
			++used[lastStrIndex];
			
			int lastLength = search(lastid);
			if (lastLength > 0)
			{
				int newLength = lastLength + str[lastStrIndex].length() - same[i][lastStrIndex];
				if (newLength > cache[id]) cache[id] = newLength;
			}
		}
	}
	
	//still no value, so cannot reach
	if (cache[id] == -1) cache[id] = -2;
	
	return cache[id];
}

int main()
{
	memset(cache, 0xFF, sizeof(cache));	

#ifdef FILE_IO
	ifstream cin("dragon.in");
	ofstream cout("dragon.out");
#endif

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}
	
	char start;
	cin >> start;
	
	//same length cache
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			same[i][j] = sameLength(str[i], str[j]);
		}
	}
	
	int used[50] = {0};
	
	for (int i = 0; i < n; ++i)
	{
		++used[i];
		int id = getId(used, i);
		if (str[i][0] == start)
		{
			cache[id] = str[i].length();
		}
		else
		{
			//first letter mismatch, cannot reach
			cache[id] = -2;
		}
		--used[i];
	}

	int maxDragonLength = 0;
	//enum. states
	for (int i = 0; i < n * threePow[n]; ++i)
	{
		int f = search(i);
		if (f > maxDragonLength) maxDragonLength = f;
	}
	
	cout << maxDragonLength << endl;
	return 0;
}