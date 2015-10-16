#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int aHeight = 165; aHeight <= 185; ++aHeight)
	{
		for (int bHeight = 165; bHeight <= 185; ++bHeight)
		{
			for (int cHeight = 165; cHeight <= 185; ++cHeight)
			{
				for (int dHeight = 165; dHeight <= 185; ++dHeight)
				{
					bool conA = (aHeight - bHeight) >= 5 && (aHeight - bHeight) <= 10;
					int diffAD = abs(aHeight - dHeight);
					bool conB = diffAD >= 2 && diffAD <= 12;
					bool conC = (cHeight + bHeight) == (175 * 2);
					bool conD = (dHeight * 3) == (aHeight + bHeight + cHeight);
					
					if (conA && conB && conC && conD)
					{
						cout << aHeight << " " << bHeight << " " << cHeight << " " << dHeight << endl;
					}
				}
			}
		}
	}
	return 0;
}