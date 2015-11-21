#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<string> strings;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        strings.push_back(s);
    }
    sort(strings.begin(), strings.end());
    for (int i = 0; i < n; ++i)
    {
        cout << strings[i] << endl;
    }
	return 0;
}