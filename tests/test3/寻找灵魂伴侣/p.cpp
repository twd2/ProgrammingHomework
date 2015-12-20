#include <fstream>
using namespace std;

int main()
{
	ifstream cin("gene.in");
	ofstream cout("gene.out");
	
	int m, n, a[200][200];
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
	
	cin.close();
	cout.close();
	return 0;
}