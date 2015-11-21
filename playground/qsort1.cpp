#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void mysort(int *begin, int *end)
{
	//cout << begin << "~" << end << endl;
	if (end <= begin + 1) return;
	
	int length = end - begin;
	//cout << length << endl;
	int *left = begin, *right = end - 1;
	
	int *ptrPivot = left + rand() % length;
	int pivot = *ptrPivot; //left hand

	//cout << "pick: " << pivot << endl;

	//make partition
	while (left <= right)
	{
		int temp; //temporary area
		
		//find a smaller number
		while (left <= right && (*right > pivot || right == ptrPivot))
		{
			if (right < ptrPivot)
			{
				*(right + 1) = *right;
			}
			--right;
		}
		if (left <= right && *right <= pivot)
		{
			temp = *right;
			//cout << "temp: " << temp << endl;
		}
		//find a lager number
		while (left <= right && (*left < pivot || left == ptrPivot))
		{
			if (left > ptrPivot)
			{
				*(left - 1) = *left;
			}
			++left;
		}
		if (left <= right && *left >= pivot)
		{
			if (right < ptrPivot)
			{
				*(right + 1) = *left;
			}
			else
			{
				*right = *left;
			}
			--right;
		
			if (left > ptrPivot)
			{
				*(left - 1) = temp;
			}
			else
			{
				*left = temp;
			}
			++left;
		}
		
		/*for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;*/
	}
	if (left > ptrPivot)
	{
		*(left - 1) = pivot;
	}
	else
	{
		*left = pivot;
	}
	//*left = pivot;
	/*cout << "[" << left - a << "] = " << pivot << endl;
	for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
	cout << endl;*/

	if (left > ptrPivot)
	{
		mysort(begin, left - 1);
	}
	else
	{
		mysort(begin, left);
	}
	if (right < ptrPivot)
	{
		mysort(right + 1 + 1, end);
	}
	else
	{
		mysort(right + 1, end);
	}
}

bool check(int *a, int *b, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main()
{
	srand(time(NULL));
	
	int n = 1000000;
	int *a, *b;
	a = new int[n];
	b = new int[n];
	
	int count = 10;
	
	while (count --> 0)
	{
		//generate random numbers
		for (int i = 0; i < n; ++i)
			a[i] = rand();
		for (int i = 0; i < n; ++i)
			b[i] = a[i];
		
		
		/*for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;*/
		
		cout << "-" << endl;
		mysort(a, a + n);
		cout << "." << endl;
		sort(b, b + n);
		cout << ".." << endl;
		
		if (!check(a, b, n))
		{
			cout << "FALSE" << endl;
			for (int i = 0; i < n; ++i)
				cout << a[i] << " ";
			cout << endl;
			for (int i = 0; i < n; ++i)
				cout << b[i] << " ";
			cout << endl;
		}
		else
		{
			//cout << "true" << endl;
		}
	}
	delete a;
	return 0;
}