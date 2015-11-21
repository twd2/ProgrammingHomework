#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("inp");
    ofstream fout;
    fout.open("oup");
    char buffer[1024 * 1024];
    int length = 0;
    char buf;
    while (fin.get(buf))
    {
        buffer[length] = buf;
        ++length;
    }
    for (int i = length - 1; i >= 0; --i)
    {
        fout.put(buffer[i]);
    }
    fin.close();
    fout.close();
	return 0;
}