#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string str;
	int len = 0, lineCount = 0;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	while (getline(fin, str))
	{
		++lineCount;
		len += str.length() + 1; // \n
	}
	--len;
	
	fout << len << " byte(s)." << endl;
	fout << lineCount << " line(s)." << endl;
	
	fin.close();
	fout.close();
	return 0;
}