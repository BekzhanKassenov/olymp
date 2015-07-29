/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int m;

	scanf("%d", &m);

	int val = 1000000;

	int tmp;

	for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			val = min(val, tmp);
	  	}

	int n;

	scanf("%d", &n);

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a.rbegin(), a.rend());

	int can = 0;

	int uk = 0;

	long long ans = 0;

	int cnt = 0;

	for (int i = 0; i < n; i++)
		{
			if (can)
				{
					can--;
					continue;
				}
			else
				{
					cnt++;
					ans += a[i];

					if (cnt == val)
						{
							cnt = 0;
							can = 2;
						}
				}
		}

	cout << ans;

	return 0;
}
