#include <iostream>
using namespace std;

int n, m, k, w, h;

void printRest(int x, int y)
{
	if (y < m)
	{
		for (int a = x; a < w - 1; ++a)
		{
			cout << " ";
		}
		if (y < m - 1)
			cout << "|";
		else
			cout << "+";
	}
	else
	{
		for (int a = x; a < w - 2 - (y - m); ++a)
		{
			cout << " ";
		}
		cout << "/";
		for (int a = w - 1 - (y - m) ; a < w; ++a)
		{
			cout << ".";
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	w = n + k - 1;
	h = m + k - 1;
	for (int x = 0; x < w - n; ++x) cout << ".";
	cout << "+";
	for (int x = 0; x < n - 2; ++x) cout << "-";
	cout << "+";
	cout << endl;
	for (int y = 1; y < k - 1; ++y)
	{
		for (int x = 0; x < w - n - y; ++x) cout << ".";
		cout << "/";
		for (int x = 0; x < n - 2; ++x) cout << " ";
		cout << "/";
		printRest(w - y, y);
		cout << endl;
	}
	cout << "+";
	for (int x = 0; x < n - 2; ++x) cout << "-";
	cout << "+";
	printRest(n, k - 1);
	cout << endl;
	for (int y = 1; y < m - 1; ++y)
	{
		cout << "|";
		for (int x = 0; x < n - 2; ++x) cout << " ";
		cout << "|";
		printRest(n, y + k - 1);
		cout << endl;
	}
	cout << "+";
	for (int x = 0; x < n - 2; ++x) cout << "-";
	cout << "+";
	for (int x = n; x < w; ++x) cout << ".";
	cout << endl;
	return 0;
}