#include <iostream>
using namespace std;

struct person_; //declaration
typedef struct person_ person;
typedef person *ptrPerson;

struct person_
{
	int id;
	ptrPerson next;
};

//returns last person
ptrPerson makeList(int n)
{
	ptrPerson head = new person, current = head;
	head->id = 0;
	for (int i = 1; i <= n - 1; ++i)
	{
		ptrPerson newPerson = new person;
		newPerson->id = i;
		current->next = newPerson;
		current = current->next;
	}
	current->next = head;
	return current;
}

void removeNext(ptrPerson perv)
{
	if (perv == NULL || perv->next == NULL) return;
	ptrPerson nextNext = perv->next->next;
	delete perv->next;
	perv->next = nextNext;
}

void deleteList(ptrPerson ptr)
{
	if (ptr == NULL) return;
	while (ptr->next != ptr)
	{
		removeNext(ptr);
	}
	delete ptr;
	ptr = NULL;
}

int main()
{
	int n, m;
	cin >> n >> m;
	ptrPerson prev = makeList(n), current = prev->next;
	
	int count = 1;
	while (current->next != current) //more than one person
	{
		if (count == m) //kill person
		{
			removeNext(prev); //remove current
			current = prev->next;
		}
		else
		{
			prev = current;
			current = prev->next;
		}
		
		++count;
		if (count > m)
		{
			count = 1;
		}
	}
	cout << current->id << endl;
	return 0;
}