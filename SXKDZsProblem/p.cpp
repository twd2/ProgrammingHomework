#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

vector<string> split(const string &s, const string &delim)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last);
	vector<string> vec_ret;

	while (index != string::npos)
	{
		vec_ret.push_back(s.substr(last, index - last));
		last = index + 1;
		index = s.find_first_of(delim, last);
	}
	if (index - last > 0)
	{
		vec_ret.push_back(s.substr(last, index - last));
	}
	return vec_ret;
}

int indexOf(const vector<string> &a, const string &s)
{
    int size=a.size();
    for (int i=0;i<size;++i)
    {
        if(a[i]==s) return i;
    }
    return -1;
}

bool hasIntersection(const vector<string> &a, const vector<string> &b)
{
    for(vector<string>::iterator it=a.begin();it!=a.end();++it)
    {
        if(indexOf(b, *it)>=0) return true;
    }
    return false;
}

void combine(vector<string> &a, vector<string> &b)
{
    for(vector<string>::iterator it=b.begin();it!=b.end();++it)
    {
        if(indexOf(a, *it)<0) a.push_back(it);
    }
    b.erase();
}

int main()
{
    vector< vector<string> > friendCircle;
    
    while (true) {

		string nameLine;
		getline(cin, nameLine);
		if (nameLine.size()==0 || cin.eof()) {
			break;
		}

		nameLine.erase(0, 1);
		nameLine.erase(nameLine.size() - 1, 1);

		vector<string> friendName = split(nameLine, string(" "));

        friendCircle.push_back(friendName);
	}
    return 0;
}