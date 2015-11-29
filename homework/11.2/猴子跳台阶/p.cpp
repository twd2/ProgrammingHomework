#include <iostream>
using namespace std;

int x, y;

int jump(int n)
{
	if (n < 0) return 0;
	if (n <= 0) return 1;
	return jump(n - x) + jump(n - y);
}

int main()
{
	int n;
	cin >> n >> x >> y;
	cout << jump(n) << endl;
	return 0;
}