#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find(vector<string> &lines, int n)
{
	if ((n & 1) == 1)
		return n;
		
	for (int i = 0; i < n / 2; ++i)
	{
		if (lines[i] != lines[n - i - 1])
			return n;
	}
	
	return find(lines, n / 2);
}

int main()
{
	string line;
	vector<string> lines;
	int n, m;
	char ch;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		line = "";
		for (int j = 0; j < m; ++j)
		{
			cin >> ch;
			line += ch;
		}
		lines.push_back(line);
	}
	/*for (int i = 0; i < n; ++i)
	{
		cout << lines[i] << endl;
	}*/
	int ans = find(lines, n);
	cout << ans << endl;
	return 0;
}