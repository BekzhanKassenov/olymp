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
#include <algorithm>
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
#define VI vector <int>

int n;

vector <PII> p;

vector <bool> used;

set <int> er;

vector <VI> g;

void dfs(int v)
{
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (!used[to])
				dfs(to);
		}
}

int dfs()
{
	used.assign(n, 0);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				dfs(i);
				ans++;
			}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].F >> p[i].S;
	g.resize(n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (p[i].F == p[j].F || p[j].S == p[i].S)
				{
					g[i].PB(j);
					g[j].PB(i);
				}
	int c = dfs();
	cout << c - 1 << endl;
	return 0;
}
