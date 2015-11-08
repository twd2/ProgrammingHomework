#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct world_;
typedef struct world_ world;
struct world_
{
	int id;
	int blockId;
	bool filled;
	
	vector<int> links;
};

vector<world> worlds;
int n;
	
void SwapLinks(int a, int b)
{
	vector<int> temp;
	temp = worlds[a].links;
	worlds[a].links = worlds[b].links;
	worlds[b].links = temp;
}

void MoveLinks(int c)
{
	vector<world> oldWorlds(worlds);

	for (int i = 1; i <= n; ++i)
	{
		worlds[((i + c - 1) % n) + 1].links = oldWorlds[i].links;
	}
}

void Fill(int startId, int blockId)
{
	for (int i = 1; i <= n; ++i)
	{
		worlds[i].filled = false;
	}
	queue<int> Q;
	Q.push(startId);
	
	while (Q.size() > 0)
	{
		int currentWorldId = Q.front();
		Q.pop();
		
		world *currentWorld = &worlds[currentWorldId];
		
		if (currentWorld->filled)
		{
			continue;
		}
		else
		{
			currentWorld->filled = true;
			currentWorld->blockId = blockId;
		}
		
		for (int i = 0; i < currentWorld->links.size(); ++i)
		{
			int linkTo = currentWorld->links[i];
			if (!worlds[linkTo].filled)
			{
				Q.push(linkTo);
			}
		}
	}	
}

int CountBlocks()
{
	int blockId = 0;
	bool blocks[1000] = {false};
	
	for (int i = 1; i <= n; ++i)
	{
		worlds[i].blockId = 0;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (worlds[i].blockId == 0)
		{
			Fill(i, ++blockId);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		//cout << "world" << i << ": " << worlds[i].blockId << endl;
		blocks[worlds[i].blockId] = true;
	}
	
	int count = 0;

	for (int i = 1; i <= blockId; ++i)
	{
		if (blocks[i]) ++count;
	}
	
	return count;
}

int main()
{
	int commandCount;
	cin >> n >> commandCount;
	
	world fake;
	worlds.push_back(fake);
	
	for (int i = 1; i <= n; ++i)
	{
		int to;
		cin >> to;
		world w;
		w.id = i;
		w.blockId = 0;
		w.filled = false;
		w.links.push_back(to);
		worlds.push_back(w);
	}
	
	while (commandCount --> 0)
	{
		int command;
		int paramA, paramB;
		cin >> command;
		if (command == 1)
		{
			cin >> paramA >> paramB;
			SwapLinks(paramA, paramB);
		}
		else if (command == 2)
		{
			cin >> paramA;
			MoveLinks(paramA);
		}

		cout << CountBlocks() << endl;
		
	}
	return 0; 
}