#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

string toString(long long a)
{
	string s;
	stringstream ss;
	ss << a;
	ss >> s;
	return s;
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    int intPart = a / b;
    a -= intPart * b;
    string answer(toString(intPart));
    //cout << answer << endl;
    if (a > 0)
    {
        answer += ".";
        map<int, int> positions;
        while (a > 0)
        {
            if (positions[a] > 0)
            {
                answer = answer.substr(0, positions[a]) + "(" + answer.substr(positions[a]) + ")";
                break;
            }
            
            positions[a] = answer.length();
            a *= 10;
            intPart = a / b;
            a -= intPart * b;
            answer += toString(intPart);
            
            //cout << answer << endl;
        }
    }
    cout << answer << endl;
    return 0;
}