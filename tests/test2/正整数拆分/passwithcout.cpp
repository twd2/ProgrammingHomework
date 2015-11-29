#include <iostream>
#include <vector>
using namespace std;
 
struct task
{
	int sum, last;
	vector<int> list;
	task *next;
};

// TODO: avoid global variable
task *head = NULL;
 
void push(task x)
{
	task *temp;
	temp = new task;
	*temp = x;
	temp->next = head;
	head = temp;
}
 
task pop()
{
	task *temp, t;
	temp = head;
	head = temp->next;
	t = *temp;
	t.next = NULL;
	delete temp;
	return t;
}
 
int main()
{
	int n;
	cin>>n;
	
	for(int i = 1; i <= n; i++)
	{
		task temp;
		temp.next = NULL;
		temp.list.push_back(i);
		temp.sum = i;
		temp.last = i;
		push(temp);
	}
	
	while(head != NULL)
	{
		task t;
		t = pop();
		if(t.sum == n)
		{
			for(vector<int>::iterator it = t.list.begin(); it != t.list.end(); it++)
			{
				if(it != t.list.begin()) cout << " ";
				cout << *it; 
			}
			cout << endl;
		}
		else
		{
			int end;
			end = (n - t.sum) > t.last ? t.last : (n - t.sum);
			for(int i = 1; i <= end; i++)
			{
				task temp;
				temp.next = NULL;
				temp.list = t.list;
				temp.list.push_back(i);
				temp.sum = t.sum + i;
				temp.last = i;
				push(temp);
			}
		}
	}
	
	return 0;
}
