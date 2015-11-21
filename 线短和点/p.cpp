#include <iostream>
#include <algorithm>
using namespace std;
 
struct I
{
	int left, right;
	bool covered;
	bool enable;
	
	bool contains(const int &a)
	{
		return a >= left && a <= right;
	}
	
	bool contains(const I &a)
	{
		return left <= a.left && right >= a.right;
	}
};
 
bool myCompareI(const I &a, const I &b)
{
	if (a.left < b.left) return true;
	else if (a.left > b.left) return false;
	else return a.right < b.right;
}

bool myComparePoint(const int &a, const int &b)
{
	return a >= b;
}
 
int main()
{
    I Ix[20000];
	int points[20000];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> points[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> Ix[i].left >> Ix[i].right;
		Ix[i].covered = false;
		Ix[i].enable = true;
	}
	sort(points, points + n, myComparePoint);
	
	//去除包含了更小区间的区间
	int disabledCount = 0;
	for (int i = 0; i < m; ++i)
	{
		//if (!Ix[i].enable) continue;
		for (int j = 0; j < m; ++j)
		{
			if (!Ix[j].enable || i == j) continue;
			if (Ix[j].contains(Ix[i]))
			{
				Ix[j].left = Ix[j].right = 0x7FFFFFFF;
				Ix[j].enable = false;
				++disabledCount;
				//cout << "Disabled: [" << Ix[j].left << ", " << Ix[j].right << "]" << endl;
			}
		}
	}
	sort(Ix, Ix + m, myCompareI);
		
	int ICount = m - disabledCount;
	int usedCount = 0;
	int coveredCount = 0;
	for (int i = 0; i < ICount; ++i)
	{
		if (!Ix[i].enable) continue;
		if (!Ix[i].covered)
		{
			for (int j = 0; j < n; ++j)
			{
				if (Ix[i].contains(points[j]))
				{
					Ix[i].covered = true;
					++coveredCount;
					++usedCount;
					for (int k = 0; k < ICount; ++k)
					{
						if (Ix[k].enable && !Ix[k].covered && Ix[k].contains(points[j]))
						{
							Ix[k].covered = true;
                            //cout << "Covered: [" << Ix[k].left << ", " << Ix[k].right << "]" << endl;
							++coveredCount;
						}
					}
					break;
				}
			}
		}
	}
	if (coveredCount == ICount)
	{
		cout << usedCount << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}