#include <iostream>
#include <complex>
#include <vector>
#include <cstdio>
using namespace std;

class Det
{
public:
	int n;
	vector<vector<complex<double> > > a;
	
	Det(int n): n(n), swapCount(0)
	{}
	void SwapRow(int i, int j)
	{
		if (i == j) return;
		swap(a[i], a[j]);
		++swapCount;
	}
	
	complex<double> Value()
	{
		for (int i = 0; i < n; ++i)
		{
			int firstNotZero = -1;
			for (int j = i; j < n; ++j)
			{
				if (abs(a[j][i]) != 0.0)
				{
					firstNotZero = j;
					break;
				}
			}
			if (firstNotZero == -1)
			{
				return complex<double>();
			}
			SwapRow(i, firstNotZero);
			for (int j = i + 1; j < n; ++j)
			{
				complex<double> c = -a[j][i]/a[i][i];
				//把下面的全部消掉
				for (int k = i; k < n; ++k)
				{
					a[j][k] += c * a[i][k];
				}
			}
		}
		complex<double> ans(1.0, 0.0);
		for (int i = 0; i < n; ++i)
		{
			ans *= a[i][i];
		}
		if ((swapCount & 1) == 1) ans = -ans;
		return ans;
	}

private:
	int swapCount;
};

int main()
{
	double real, imag;
	int n;
	cin >> n;
	Det det(n);
	for (int r = 0; r < n; ++r)
	{
		vector<complex<double> > row;
		for (int c = 0; c < n; ++c)
		{
			cin >> real >> imag;
			row.push_back(complex<double>(real, imag));
		}
		det.a.push_back(row);
	}
	
	complex<double> val;
	val = det.Value();
	printf("(%.4f,%.4f)\n", val.real(), val.imag());
	return 0;
}