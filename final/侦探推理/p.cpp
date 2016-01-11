#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

struct Stat
{
    int who, day;
    bool isGuilty;
};

vector<string> &split(const string &s, char delim, vector<string> &elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}
 
vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}
 
int getDayId(string dayStr)
{
    if (dayStr == "Monday.")
        return 1;
    if (dayStr == "Tuesday.")
        return 2;
    if (dayStr == "Wednesday.")
        return 3;   
    if (dayStr == "Thursday.")
        return 4;
    if (dayStr == "Friday.")
        return 5;
    if (dayStr == "Saturday.")
        return 6;  
    if (dayStr == "Sunday.")
        return 7;
    return -1;
}
 
bool check(Stat stat, int guilty, int day)
{
    if (stat.day > 0)
        return stat.day == day;
    if (stat.who >= 0)
    {
        if (guilty == stat.who && stat.isGuilty)
            return true;
        else if (guilty != stat.who && !stat.isGuilty)
            return true;
        else
            return false;
    }
    for (;;);
    return true;
}

Stat parse(map<string, int> &ids, string s, int &outWho)
{
    // parse
    Stat stat;
    stat.who = stat.day = -1;
    vector<string> statStr = split(s, ' ');
    string name = statStr[0];
    name = name.substr(0, name.size() - 1);
    int who = ids[name] - 1;
    outWho = who;
    if (statStr.size() == 4)
    {
        if (statStr[1] == "I" && statStr[2] == "am" && statStr[3] == "guilty.")
        {
            stat.who = who;
            stat.isGuilty = true;
        }
        else if (statStr[2] == "is" && statStr[3] == "guilty.")
        {
            int id = ids[statStr[1]] - 1;
            if (id >= 0)
            {
                stat.who = id;
                stat.isGuilty = true;
            }
        }
        else if (statStr[1] == "Today" && statStr[2] == "is")
        {
            int day = getDayId(statStr[3]);
            if (day > 0)
            {
                stat.day = day;
            }
        }
    }
    else if (statStr.size() == 5)
    {
        if (statStr[1] == "I" && statStr[2] == "am" && statStr[3] == "not" && statStr[4] == "guilty.")
        {
            stat.who = who;
            stat.isGuilty = false;
        }
        else if (statStr[2] == "is" && statStr[3] == "not" && statStr[4] == "guilty.")
        {
            int id = ids[statStr[1]] - 1;
            if (id >= 0)
            {
                stat.who = id;
                stat.isGuilty = false;
            }
        }
    }
    return stat;
}
 
int main()
{
    vector<string> names;
    map<string, int> ids;
    vector<vector<Stat> > stats;
    int m, n, p;
    cin >> m >> n >> p;
    string s;
    getline(cin, s); // drop
    for (int i = 0; i < m; ++i)
    {
        getline(cin, s);
        names.push_back(s);
        stats.push_back(vector<Stat>());
        ids[s] = i + 1;
    }
    for (int i = 0; i < p; ++i)
    {
        getline(cin, s);
        int who;
        Stat stat = parse(ids, s, who);
        if (stat.who >= 0 || stat.day > 0)
        {
            stats[who].push_back(stat);
        }
    }
    
    int trueGuilty = -1, guiltyCount = 0;
    for (int tryDay = 1; tryDay <= 7; ++tryDay)
    {
        for (int tryGuilty = 0; tryGuilty < m; ++tryGuilty)
        {
            int alwaysFalseCount = 0, nothingCount = 0;
            bool out = false;
            for (int i = 0; i < m; ++i)
            {
                int trueCount = 0;
                for (int j = 0; j < stats[i].size(); ++j)
                {
                    if (check(stats[i][j], tryGuilty, tryDay))
                    {
                        ++trueCount;
                    }
                }
                if (trueCount != 0 && trueCount != stats[i].size())
                {
                    out = true;
                    break;
                }
                if (stats[i].size() == 0)
                    ++nothingCount;
                if (stats[i].size() > 0 && trueCount == 0)
                    ++alwaysFalseCount;
            }
            if (out) continue;
            
            //                           said nothing: 'always false' and 'always true' are both OK
            if (alwaysFalseCount == n || alwaysFalseCount + nothingCount == n)
            {
                //found!
                
                //already found
                if (trueGuilty >= 0 && trueGuilty != tryGuilty)
                {
                    // multi
                    ++guiltyCount;
                    break;
                }
                else if (trueGuilty < 0)
                {
                    trueGuilty = tryGuilty;
                    ++guiltyCount;
                }
            }
        }
        if (guiltyCount > 1)
        {
            break;
        }
    }
    
    if (guiltyCount == 0)
    {
        cout << "Impossible" << endl;
    }
    else if (guiltyCount > 1)
    {
        cout << "Cannot Determine" << endl;
    }
    else
    {
        cout << names[trueGuilty] << endl;
    }
	return 0;
}