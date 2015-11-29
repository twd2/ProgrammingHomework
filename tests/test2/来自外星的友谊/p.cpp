#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("chat.in");
	ofstream fout("chat.out");
	string s;
	bool a = true;
	while (getline(fin, s))
	{
		if (s == "") break;
		if (a)
		{
			fout << "Elliott: " << s << endl;
		}
		else
		{
			fout << "ET: " << s << endl;
		}
		a = !a;
	}
	fin.close();
	fout.close();
	return 0;
}
