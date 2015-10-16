#include <iostream>
using namespace std;

int main()
{
	for (int row = 1; row <= 9; ++row)
	{
		for (int col = 1; col <= row; ++col)
		{
			cout << row << "*" << col << "=" << row * col;
			if (col < row)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}