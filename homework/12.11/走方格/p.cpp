#include <iostream>
using namespace std;

struct task
{
	int x, y, step;
};

int n;
unsigned int minStep = -1;
bool checked[1050][1050] = {{0}};
char m[1050][1050] = {{0}};
#define Q_LENGTH 10000000
task Q[Q_LENGTH];
int qHead = 0, qTail = 0;

inline bool check(int x, int y)
{
	return !checked[y][x] && x >= 0 && x < n && y >=0 && y < n && m[y][x] != '#';
}

void foo()
{
	//init queue
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (m[i][j] == 'S')
			{
				task t;
				t.x = j;
				t.y = i;
				t.step = 0;
				Q[qTail] = t;
				++qTail;
				qTail %= Q_LENGTH;
			}
		}
	}
	
	while (qHead < qTail)
	{
		task t = Q[qHead];
		++qHead;
		qHead %= Q_LENGTH;
		
		if (checked[t.y][t.x])
			continue;
		
		if (m[t.y][t.x] == 'E')
		{
			if (minStep > t.step) minStep = t.step;
			continue;
		}
		
		checked[t.y][t.x] = true;
		
		if (check(t.x - 1, t.y))
		{
			task newTask;
			newTask.x = t.x - 1;
			newTask.y = t.y;
			newTask.step = t.step + 1;
			Q[qTail] = newTask;
			++qTail;
			qTail %= Q_LENGTH;
		}
		
		if (check(t.x + 1, t.y))
		{
			task newTask;
			newTask.x = t.x + 1;
			newTask.y = t.y;
			newTask.step = t.step + 1;
			Q[qTail] = newTask;
			++qTail;
			qTail %= Q_LENGTH;
		}
		
		if (check(t.x, t.y - 1))
		{
			task newTask;
			newTask.x = t.x;
			newTask.y = t.y - 1;
			newTask.step = t.step + 1;
			Q[qTail] = newTask;
			++qTail;
			qTail %= Q_LENGTH;
		}
		
		if (check(t.x, t.y + 1))
		{
			task newTask;
			newTask.x = t.x;
			newTask.y = t.y + 1;
			newTask.step = t.step + 1;
			Q[qTail] = newTask;
			++qTail;
			qTail %= Q_LENGTH;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i];
	}
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