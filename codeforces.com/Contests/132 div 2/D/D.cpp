/*********************************************
**       Solution by Bekjan Kasenov         **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 1000000000
#define EPS 10e-14
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define int long long
#define VI vector <int>

main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n, m;
	cin >> n >> m;
	int T, t, x, cost;
	int ans = 0;
	for (int i = 0; i < n; i++)
		{
			cin >> t >> T >> x >> cost;
			if (T - t > 0 && T - t > m)
				{
					ans += cost;
					continue;
				}
			if (t >= T)
				ans += (x * m + cost);
			else
				{
					int a = 0;
					a += m / (T - t);
					if (m % (T - t) != 0)
						a++;
					ans += min(x * m + cost, cost * a);
				} 
		}
	cout << ans;
	return 0;
}
