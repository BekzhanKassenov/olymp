/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 1000000000
#define EPS 10E-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define VI vector <int>

bool check(int x, int y)
{
	bool u1[10] = {0};
	while (x)
		{
			u1[x % 10] = 1;
			x /= 10;
		}
	while (y)
		{
			if (u1[y % 10])
				return true;
			y /= 10;
		}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
				{
					if (check(n, i))
						ans++;
					if (i * i != n && check(n, n / i))
						ans ++;
				}
			 
		}
	cout << ans;
	return 0;
}
