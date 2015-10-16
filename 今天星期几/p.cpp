#include <iostream>
using namespace std;

int main()
{
	int is[8], isNot[8];
	for (int i = 0; i < 8; ++i)
	{
		cin>>is[i]>>isNot[i];
	}
	
	for (int day = 1; day <= 7; ++day)
	{
		bool found = true;
		for (int i = 0; i < 8; ++i)
		{
			if ((is[i] == day) + (isNot[i] != day) != 1)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout<<day<<endl;
			break;
		}
	}
	return 0;
}