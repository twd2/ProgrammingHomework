#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//sort [begin, end)
void mysort(int *begin, int *end)
{
	if (end <= begin + 1) return;
	
	int length = end - begin;
	int *left = begin, *right = end - 1;
	
	//pick a pivot randomly
	int *ptrPivot = left + rand() % length;
	int pivot = *ptrPivot; //left hand

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
	}
	if (left > ptrPivot)
	{
		--left;
	}
	if (right < ptrPivot)
	{
		++right;
	}
	
	//place pivot where it should be
	*left = pivot;

	//left part
	mysort(begin, left);
	
	//right part
	mysort(left + 1, end);
}

bool check(int *a, int *b, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

void hello()
{
	int n;
	cin >> n;
	int *a;
	a = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	mysort(a, a + n);
	
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	delete [] a;
}

int main()
{
	srand(time(NULL));
	
	hello();
	return 0;
	
	int n = 1000000;
	int *a, *b;
	a = new int[n];
	b = new int[n];
	
	int count = 100;
	
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
	delete [] a;
	delete [] b;
	return 0;
}