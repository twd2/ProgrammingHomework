#include <iostream>
using namespace std;
 
struct task
{
	int x, y;
	int step;
};
 
int n;
int sx, sy, ex, ey;
int minStep = 10000001;
bool checked[2000][2000] = {{0}};
char m[2000][2000] = {{0}};
int dis[2000][2000] = {{0}};
int dx[] =   {1, 0, -1,  0};
int dy[] =   {0, 1,  0, -1};
int cost[] = {1, 1,  1,  1};
#define Q_LENGTH 10000000
task Q[Q_LENGTH];
int qHead = 0, qTail = 0;
 
inline bool check(int x, int y) 
{
	return !checked[y][x] && x >= 0 && x < n && y >= 0 && y < n && m[x][y] == '0';
	//                                                              ^^^^^^WTF
}
 
void foo()
{
	//init queue
	task t0;
	t0.x = sx;
	t0.y = sy;
	t0.step = 0;
	
	Q[qTail] = t0;
	++qTail;
	qTail %= Q_LENGTH;
	
	while (qHead < qTail)
	{
		task t = Q[qHead];
		++qHead;
		qHead %= Q_LENGTH;
		
		if (checked[t.y][t.x])
			continue;
		
		if (t.y == ey && t.x == ex)
		{
			if (minStep > t.step) minStep = t.step;
			continue;
		}
		
		checked[t.y][t.x] = true;
		
		for (int i = 0; i < 4; ++i)
		{
			if (check(t.x + dx[i], t.y + dy[i]))
			{
				task newTask;
				newTask.x = t.x + dx[i];
				newTask.y = t.y + dy[i];
				newTask.step = t.step + cost[i];
				Q[qTail] = newTask;
				++qTail;
				qTail %= Q_LENGTH;
			}
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
	cin >> sx >> sy >> ex >> ey;
	--sx;
	--sy;
	--ex;
	--ey;
 
	foo();
	
	if (minStep == 10000001)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << minStep << endl;
	}
	return 0;
}