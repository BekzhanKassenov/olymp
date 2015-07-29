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

vector <vector <int> > g;

vector <int> col;

int n, m;

void dfs(int v)
{
	int cnt = 0;

	for (size_t i = 0; i < g[v].size(); i++)
		if (col[g[v][i]] == col[v])
			cnt++;

	if (cnt > 1)
		{
			col[v] ^= 1;

			for (size_t i = 0; i < g[v].size(); i++)
				if (col[g[v][i]] == col[v])
					dfs(g[v][i]);
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	cin >> n >> m;

	int x, y;

	g.resize(n);
	col.resize(n, 0);

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			x--, y--;

			g[x].push_back(y);
			g[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		{
			dfs(i);
		}

	for (int i = 0; i < n; i++)
		cout << col[i];

	cout << endl;	

	return 0;
}
