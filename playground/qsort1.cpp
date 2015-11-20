#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int n = 10;
int *a;
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
		while (left <= right && (*right >= pivot || right == ptrPivot))
		{
			if (right < ptrPivot)
			{
				*(right + 1) = *right;
			}
			--right;
		}
		if (left <= right && *right < pivot)
		{
			temp = *right;
			//cout << "temp: " << temp << endl;
		}
		//find a lager number
		while (left <= right && (*left <= pivot || left == ptrPivot))
		{
			if (left > ptrPivot)
			{
				*(left - 1) = *left;
			}
			++left;
		}
		if (left <= right && *left > pivot)
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
	
	//I assume left == right
	
	//*left = pivot;
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
	srand(time(NULL));
	
	int n = 10;
	a = new int[n];
	
	int count = 100;
	
	while (count --> 0)
	{
		for (int i = 0; i < n; ++i)
			a[i] = rand() % 100;
		
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		
		mysort(a, a + n);

		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		
		if (!check(a, a + n))
		{
			cout << "FALSE" << endl;
		}
	}
	delete a;
	return 0;
}