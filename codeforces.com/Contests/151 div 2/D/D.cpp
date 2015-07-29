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

	int n, v;

	scanf("%d%d", &n, &v);

	vector <int> c(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	map <int, set <int> > m;

	for (int i = 0; i < v; i++)
		{
			int x, y;

			scanf("%d%d", &x, &y);

			x--;
			y--;

			if (c[x] != c[y])
			 	{
					m[c[x]].insert(c[y]);
					m[c[y]].insert(c[x]);
				}
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			int s1 = m[c[i]].size();
			int s2 = m[c[ans]].size();

			if (s1 > s2)
				ans = i;
			else
				if (s1 == s2 && c[i] < c[ans])
					ans = i;	
		}

	cout << c[ans];

	return 0;
}
