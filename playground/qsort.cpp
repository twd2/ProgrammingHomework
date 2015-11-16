#include <iostream>
#include <cstdlib>
using namespace std;
void mysort(int *begin, int *end)
{
	//cout << begin << "~" << end << endl;
	if (end <= begin + 1) return;
	
	int *left = begin, *right = end - 1;
	
	int pivot = *left;
	//分区
	while (left < right)
	{
		while (right > left && *right >= pivot)
			--right;
		if (right > left)
			*left = *right;
		while (left < right && *left <= pivot)
			++left;
		if (left < right)
			*right = *left;
	}
	//left == right
	*left = pivot;
	//cout << "[" << left - a << "] = " << pivot << endl;
	//for (int i = 0; i < n; ++i)
	//	cout << a[i] << " ";
	//cout << endl;
	//system("read");
	mysort(begin, left);
	mysort(right + 1, end);
}

bool check(int *begin, int *end)
{
	if (end <= begin + 1) return true;
	int *current = begin;
	while (current < end - 1)
	{
		if (*current > *(current + 1)) return false;
		++current;
	}
	return true;
}

int main()
{
	int n = 100000;
	int *a = new int[n];
	
	int count = 1;
	
	while (count --> 0)
	{
		for (int i = 0; i < n; ++i)
			a[i] = rand();
		
		mysort(a, a + n);
		if (!check(a, a + n))
		{
			cout << "FALSE" << endl;
		}
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		
	}
	delete a;
	return 0;
}