#include <iostream>
#include <cstring>
using namespace std;

struct task
{
	int water, step;
};

unsigned int minStep = -1;
bool checked[10050] = {0};
int n, m, a[150] = {0}, b[150] = {0};
int p, q;

#define Q_LENGTH 10000000
task Q[Q_LENGTH];
int qHead = 0, qTail = 0;

void foo()
{
	while (qHead < qTail)
	{
		task t = Q[qHead];
		++qHead;
		qHead %= Q_LENGTH;
		
		if (t.water == q)
		{
			if (minStep > t.step) minStep = t.step;
			continue;
		}
		
		checked[t.water] = true;
	
		//取水
		for (int i = 0; i < n; ++i)
		{
			if (t.water + a[i] <= p)
			{
				task newTask;
				newTask.step = t.step + 1;
				newTask.water = t.water + a[i];
				if (!checked[newTask.water])
				{
					Q[qTail] = newTask;
					++qTail;
					qTail %= Q_LENGTH;
				}
			}
		}
		
		//抽水
		for (int i = 0; i < m; ++i)
		{
			task newTask;
			newTask.step = t.step + 1;
			newTask.water = t.water - b[i];
			if (newTask.water < 0) newTask.water = 0;
			if (!checked[newTask.water])
			{
				Q[qTail] = newTask;
				++qTail;
				qTail %= Q_LENGTH;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> p >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	
	task t;
	t.step = 0;
	t.water = 0;
	Q[qTail] = t;
	++qTail;
	qTail %= Q_LENGTH;
	
	foo();
	
	if (minStep == (unsigned int)-1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << minStep << endl;
	}
	return 0;
}