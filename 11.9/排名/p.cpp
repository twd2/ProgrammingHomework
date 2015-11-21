#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
	int id;
	string name;
	int score;	
};

bool CompareStudent(const Student &a, const Student &b)
{
	if (a.score < b.score)
		return false;
	else if (a.score > b.score)
		return true;
	else
		return a.id < b.id;
}

int main()
{
	Student students[100050];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		students[i].id = i;
		cin >> students[i].name >> students[i].score;
	}
	sort(students, students + n, CompareStudent);
	for (int i = 0; i < n; ++i)
	{
		cout << students[i].name << endl;
	}
	return 0;
}