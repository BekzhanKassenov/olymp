/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS
#define File "connect2"

vector <vector <int> > g;

vector <bool> used;

int n, m;

void dfs(int v)
{
	used[v] = true;

	for (int i = 0; i < n; i++)
		if (g[v][i] && !used[i])
			dfs(i);
}

int main()
{
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n >> m;

	g.assign(n, vector <int> (n));

	used.assign(n, false);

	for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			y--, x--;

			g[x][y] = g[y][x] = 1;
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			if (!used[i])
				{
					dfs(i);
					ans++;
				}
		}

	cout << ans;	

	return 0;
}
