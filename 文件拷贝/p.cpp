#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("inp");
    ofstream fout;
    fout.open("oup");
    char buffer;
    while (fin.get(buffer))
    {
        fout.put(buffer);
    }
    fin.close();
    fout.close();
	return 0;
}