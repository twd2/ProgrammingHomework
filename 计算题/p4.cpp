#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.14159265358979

int main()
{
	printf("%.5f\n", pow(sin(PI / 4), 2.0) + sin(PI / 4) * cos(PI / 4) - pow(cos(PI / 4), 2.0));
	return 0;
}