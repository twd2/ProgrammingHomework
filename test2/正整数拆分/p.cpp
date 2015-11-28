#include <cstdio> //似乎必须要使用printf，否则会超时
using namespace std;

void foo(int n, int *data, int size)
{
	if (n < 0) return;
	if (n == 0) //分完了 
	{
		for (int i = 0; i < size; ++i)
		{
			printf("%d", data[i]);
			if (i < size - 1) 
				printf(" ");
		}
		printf("\n");
	}
	
	int start = n;
	if (size >= 1)
	{
		start = data[size - 1];
	}
	
	for (int i = start; i > 0; --i)
	{
		data[size] = i;
		foo(n - i, data, size + 1);
	}
}

int main()
{
	int n, data[100];
	scanf("%d", &n);
	foo(n, data, 0);
	return 0;
}
