#include <iostream>
using namespace std;

int main()
{
	int n, t, color[1000];
	cin >> n >> t;
	for (int i = 0; i < n; ++i)
	{
		cin >> color[i];
	}
	
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	
	int maxBeauty = 1;
	for (int l = 0; l < n; ++l)
	{
		for (int r = l + 1; r < n; ++r)
		{
			if (color[l] != color[r]) continue;
			int left = l, right = r;
			int timeUsage = 0;
			bool found = false;
			int searchL = l + 1, searchR = r - 1;
			do
			{
				found = false;
				for (int i = searchL; i <= searchR; ++i)
				{
					if (color[i] != color[l])
					{
						if (i - left < right - i) // move to left
						{
							timeUsage += i - left;
							++left;
						}
						else // move to right
						{
							timeUsage += right - i;
							--right;
						}
						searchL = i + 1;
						found = true;
						break;
					}
				}
				for (int i = searchR; i >= searchL; --i)
				{
					if (color[i] != color[l])
					{
						if (i - left < right - i) // move to left
						{
							timeUsage += i - left;
							++left;
						}
						else // move to right
						{
							timeUsage += right - i;
							--right;
						}
						searchR = i - 1;
						found = true;
						break;
					}
				}
			} while (found);
			int currentBeauty = right - left + 1;
			if (timeUsage <= t)
			{
				if (maxBeauty < currentBeauty) maxBeauty = currentBeauty;
			}
			//cout << right - left + 1 << " " << timeUsage << endl;
		}
	}
	cout << maxBeauty << endl;
	return 0;
}