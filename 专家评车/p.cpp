#include <iostream>
using namespace std;

int main()
{
	bool A, B, C, D;
	for (int car = 1; car <= 4; ++car)
	{
		A = (car == 2);
		B = (car == 4);
		C = (car != 3);
		D = !B;
		if (A + B + C + D == 1)
		{
			cout << car << endl;
			cout << (A ? "A" : "")
				 << (B ? "B" : "")
				 << (C ? "C" : "")
				 << (D ? "D" : "")
				 << endl;
		}
	}
	return 0;
}