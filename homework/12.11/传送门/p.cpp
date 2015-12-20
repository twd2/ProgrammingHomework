#include <iostream>
#include <cstring>
using namespace std;

struct task
{
	int p1, p2, step;
};

int n;
unsigned int minStep = -1;
bool checked[1050][1050] = {{0}};
int m[1050] = {0};
int door[1050] = {0};
#define Q_LENGTH 10000000
task Q[Q_LENGTH];
int qHead = 0, qTail = 0;

bool meet(int p1, int p2)
{
	return (p1 == p2) || //两人处于同一位置
	       (m[p1] > 0 && m[p1] == m[p2]); //两人处于同一传送门的两个端口
}

void print(int p1, int p2)
{
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		if (m[i] >= 0) cout << " ";
		cout << m[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		if (i == p1 && i == p2)
			cout << " *" << " ";
		else if (i == p1)
			cout << " A" << " ";
		else if (i == p2)
			cout << " B" << " ";
		else
			cout << "  " << " ";
	}
	cout << endl;
}

void foo()
{
	while (qHead < qTail)
	{
		task t = Q[qHead];
		++qHead;
		qHead %= Q_LENGTH;
		
		if (checked[t.p1][t.p2])
			continue;
		
		if (meet(t.p1, t.p2))
		{
			if (minStep > t.step) minStep = t.step;
			continue;
		}
		
		checked[t.p1][t.p2] = true;
		
		//left
		task newTask;
		newTask.step = t.step + 1;
		if (t.p1 - 1 >= 0 && m[t.p1 - 1] >= 0)
			newTask.p1 = t.p1 - 1;
		else
			newTask.p1 = t.p1;
		
		if (t.p2 - 1 >= 0 && m[t.p2 - 1] >= 0)
			newTask.p2 = t.p2 - 1;
		else 
			newTask.p2 = t.p2;
			
		if (door[newTask.p1] >= 0)
		{
			newTask.p1 = door[newTask.p1];
		}
		if (door[newTask.p2] >= 0)
		{
			newTask.p2 = door[newTask.p2];
		}
		
		if (!checked[newTask.p1][newTask.p2])
		{
			Q[qTail] = newTask;
			++qTail;
			qTail %= Q_LENGTH;
		}
		
		//right
		newTask.step = t.step + 1;
		if (t.p1 + 1 < n && m[t.p1 + 1] >= 0)
			newTask.p1 = t.p1 + 1;
		else
			newTask.p1 = t.p1;
			
		if (t.p2 + 1 < n && m[t.p2 + 1] >= 0)
			newTask.p2 = t.p2 + 1;
		else
			newTask.p2 = t.p2;	
			
		if (door[newTask.p1] >= 0)
		{
			newTask.p1 = door[newTask.p1];
		}
		if (door[newTask.p2] >= 0)
		{
			newTask.p2 = door[newTask.p2];
		}
		
		if (!checked[newTask.p1][newTask.p2])
		{
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
	memset(door, 0xFF, sizeof(door));
	for (int i = 0; i < n; ++i)
	{
		if (m[i] > 0)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (m[j] == m[i])
				{
					//build door
					door[i] = j;
					door[j] = i;
					break;
				}
			}
		}
	}
	
	task t;
	t.step = 0;
	cin >> t.p1 >> t.p2;
	--t.p1;
	--t.p2;
	Q[qTail] = t;
	++qTail;
	qTail %= Q_LENGTH;
	
	foo();
	
	if (minStep == (unsigned int)-1)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << minStep << endl;
	}
	return 0;
}