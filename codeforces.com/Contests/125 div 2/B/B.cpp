#include <iostream>
#include <cmath>

using namespace std;

int x,y,x2,y2,r1,r2,r3,r4,dist;

int sqr(int x)
{
	return x*x;
}

bool test(int rx, int ry)
{
	if (dist == sqr(rx-ry) || dist == sqr(rx+ry))
		return true;
	if (dist>sqr(rx-ry) && sqr(rx+ry)>dist)
		return false;
	return true;
}

int main()
{
	cin >> x >> y >> r1 >> r2;
	cin >> x2 >> y2 >> r3 >> r4;
	dist =  sqr(x2-x)+sqr(y2-y);
	int ans = 0;
	if (dist <r3 || dist >r4) 
		{ 	
			if (test(r1,r3) && test(r1,r4))
				ans++;
			if (test(r2,r3) && test(r2,r4))
				ans++;
		}
	if (dist > r2 || dist < r1)
		{
			if (test(r3,r1) && test(r3,r2))
				ans++;
			if (test(r4,r1) && test(r4,r2))
				ans++;
		}
   cout << ans;
   return 0;
}
