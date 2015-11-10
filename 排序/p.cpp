#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Thing
{
	int a, b;	
};

struct Person
{
	int id;
	vector<Thing> things;
};

int CompareThings(const Thing &a, const Thing &b)
{
	if (a.a < b.a)
		return -1;
	else if (a.a > b.a)
		return 1;
	else if (a.b < b.b)
		return -1;
	else if (a.b > b.b)
		return 1;
	else 
		return 0;
}

bool CompareThingsBool(const Thing &a, const Thing &b)
{
	return CompareThings(a, b) > 0;
}

bool ComparePeople(const Person &a, const Person &b)
{
	int countA = a.things.size(), countB = b.things.size();
	int i = 0;
	while (true)
	{
		if (i >= countA && i < countB) return false; //B is more important
		if (i >= countB && i < countA) return true; //A is more important
		if (i >= countA && i >= countB) break;
		int cmp = CompareThings(a.things[i], b.things[i]);
		if (cmp != 0)
		{
			return cmp > 0;
		}
		++i;
	}
	return a.id > b.id;
}

int main()
{
	Thing things[200];
	Person people[200];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> things[i].a >> things[i].b;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int thingsCount;
		cin >> thingsCount;
		people[i].id = i;
		for (int j = 0; j < thingsCount; ++j)
		{
			int thingId;
			cin >> thingId;
			people[i].things.push_back(things[thingId - 1]);
		}
		sort(people[i].things.begin(), people[i].things.end(), CompareThingsBool);
	}
	sort(people, people + m, ComparePeople);
	
	for (int i = 0; i < m; ++i)
	{
		cout << people[i].id + 1 << endl;
	}
	return 0;
}