#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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

int indexOf(vector<string> &a, string &s)
{
    int size=a.size();
    for (int i=0;i<size;++i)
    {
        if(a[i]==s) return i;
    }
    return -1;
}

bool hasIntersection(vector<string> &a, vector<string> &b)
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
        if(indexOf(a, *it)<0) a.push_back(*it);
    }
    b.clear();
}

bool myComp(const vector<string> &a, const vector<string> &b)
{
    return !(a.size()<b.size());
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
	
	int size=friendCircle.size();	
	
	bool found=false;
	do
	{
        found=false;
        for(int i=0;i<size;++i)
        {
            for(int j=0;j<size;++j)
            {
                if(i==j) continue;
                
                vector<string> &a=friendCircle[i],
                               &b=friendCircle[j];
                if(hasIntersection(a, b)) //对于任意两个不同的集合，判断是否有交集
                {
                    found=true;
                    combine(a, b); //有就合并
                }
            }
        }
	} while(found);
	
	for(int i=0;i<size;++i)
	{
        vector<string> &a=friendCircle[i];
        sort(a.begin(), a.end());
	}
	
	sort(friendCircle.begin(), friendCircle.end(), myComp);
	
    for(int i=0;i<size;++i)
	{
        vector<string> &a=friendCircle[i];
        if(a.size()==0) break;
        int nameCount=a.size();
        cout<<"{";
        for(int j=0;j<nameCount;++j)
        {
            cout<<a[j];
            if(j<nameCount-1) cout<<" ";
        }
        cout<<"}"<<endl;
	}
    return 0;
}