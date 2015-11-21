#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;

class myvector
{
private:
	int *data;
	int cap;
	int size;
	
public:
	myvector() : cap(8), size(0)
	{
		data = (int *)malloc(cap * sizeof(int));
	}
	
	myvector(int cap) : cap(cap), size(0)
	{
		if (cap <= 0) throw "cap <= 0";
		data = (int *)malloc(cap * sizeof(int));
	}
	
	~myvector()
	{
		if (data != NULL)
		{
			free(data);
			data = NULL;
		}
	}
	
	void add(int x)
	{
		if (size == cap)
		{
			cap *= 2;
			data = (int *)realloc(data, cap * sizeof(int));
		}
		data[size] = x;
		++size;
	}
	
	int *get(int i)
	{
		return data + i;
	}
};

int main()
{
	myvector a;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a.add(x);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << *(a.get(i)) << " ";
	}
	cout << endl;
	return 0;
}