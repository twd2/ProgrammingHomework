#include <iostream>
#include <cmath>
using namespace std;

class vec2
{
public:
	int x, y;
	vec2 operator+(const vec2 &b)
	{
		vec2 result;
		result.x = x + b.x;
		result.y = y + b.y;
		return result;
	}
	
	vec2 operator-()
	{
		vec2 result;
		result.x = -x;
		result.y = -y;
		return result;
	}
	
	vec2 operator-(const vec2 &b)
	{
		vec2 result;
		result.x = x - b.x;
		result.y = y - b.y;
		return result;
	}
	
	int crossP(const vec2 &b)
	{
		return x * b.y - b.x * y;
	}
};

bool check(vec2 p, vec2 a, vec2 b, vec2 c)
{
	vec2 pa = a - p, pb = b - p, pc = c - p;
	int cp1, cp2;
	
	cp1 = pa.crossP(pb);
	cp2 = pa.crossP(pc);
	if ((cp1 < 0 && cp2 < 0) || (cp1 > 0 && cp2 > 0)) //在两侧
		return false;
	
	cp1 = pb.crossP(pa);
	cp2 = pb.crossP(pc);
	if ((cp1 < 0 && cp2 < 0) || (cp1 > 0 && cp2 > 0)) //在两侧
		return false;
	
	cp1 = pc.crossP(pb);
	cp2 = pc.crossP(pa);
	if ((cp1 < 0 && cp2 < 0) || (cp1 > 0 && cp2 > 0)) //在两侧
		return false;	 
	
	return true;
}

int main()
{
	vec2 a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	if (check(a, b, c, d))
	{
		cout << 1 << endl;
	}
	else if (check(b, a, c, d))
	{
		cout << 2 << endl;
	}
	else if (check(c, b, a, d))
	{
		cout << 3 << endl;
	}
	else if (check(d, a, b, c))
	{
		cout << 4 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
