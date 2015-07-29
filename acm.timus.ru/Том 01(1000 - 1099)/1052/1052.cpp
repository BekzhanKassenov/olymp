#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define F first
#define S second
#define abs(x) (x < 0) ? (-x) : x

int gcd(int a, int b)
{
	if (a == b)
		return a;
	if (a == 0 || b == 0)
		return a + b;
	if (a < b)
		return gcd(a, b - a);
	else
		return gcd(b, a - b);
}

struct ur
{
	int a, b, c;
};

ur func(int x, int y, int xz, int yz)
{
	ur k;
	k.a = yz - y;
	k.b = x - xz;
	k.c = - (x * yz - y * xz);
	int g = gcd(abs(k.a), gcd(abs(k.b), abs(k.c)));
	k.a /= g;
	k.c /= g;
	k.b /= g;
	return k;
}

bool operator == (ur u1, ur u2)
{
	if (u1.a == u2.a && u1.b == u2.b && u1.c == u2.c)
		return true;
	return false;
}

bool operator < (ur u1, ur u2)
{
	if (u1.a < u2.a)
		return true;
	if (u1.a > u2.a)
		return false;
	if (u1.a == u2.a)
		{
			if (u1.b < u2.b)
				return true;
			if (u1.b > u2.b)
				return false;
			if (u1.b == u2.b)
				{
					if (u1.c < u2.c)
						return true;
					if (u1.c >= u2.c)
						return false;
				}
	  }
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n;
	cin >> n;
	
	vector <pair <int, int> > a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	map <ur, set<int> > m;

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			{
				ur k = func(a[i].F, a[i].S, a[j].F, a[j].S);
				m[k].insert(i);
				m[k].insert(j);
				ans = max(ans, int(m[k].size()));
			} 
	cout << ans;
	return 0;
}
