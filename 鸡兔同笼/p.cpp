#include <iostream>
using namespace std;

int main()
{
	int head, leg;
	cin >> head >> leg;
	for (int chicken = 0; chicken <= head; ++chicken)
	{
		int rabbit = head - chicken;
		if (chicken * 2 + rabbit * 4 == leg)
		{
			cout << chicken << " " << rabbit << endl;
			break;
		}
	}
	return 0;
}