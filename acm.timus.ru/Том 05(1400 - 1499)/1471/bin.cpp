#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

vector <vector <int> > pr;

vector <vector <PII> > g;

vector <bool> used;

vector <int> tin, tout;

vector <int> dist;

int l;

int timer;

void init(int n)
{
	l = 1;

	timer = 0;

	while ((1 << l) <= n)
		l++;

	dist.resize(n, 0);

	used.resize(n);

	g.resize(n);

	pr.resize(n, vector <int> (l + 1));

	tin.resize(n);

	tout.resize(n);
}

void dfs(int v, int p = 0)
{
	used[v] = true;

	tin[v] = timer++;

	pr[v][0] = p;

	for (int i = 1; i <= l; i++)
		pr[v][i] = pr[pr[v][i - 1]][i - 1];

	for (size_t i = 0; i < g[v].size(); i++)
		{
			if (!used[g[v][i].F])
				{
					dist[g[v][i].F] = dist[v] + g[v][i].S;
					dfs(g[v][i].F, v);
				}
		}

	tout[v] = timer++;
}

bool is_anc(int a, int b)
{
	if (tin[a] <= tin[b] && tout[a] >= tout[b])
		return true;

	return false;	
}

int lca(int a, int b)
{
	if (is_anc(a, b))
		return a;

	if (is_anc(b, a))
		return b;

	for (int i = l; i >= 0; i--)
		if (!is_anc(pr[a][i], b))
			a = pr[a][i];

	return pr[a][0];
}

int query(int a, int b)
{
	int c = lca(a, b);

	return (dist[a] + dist[b] - 2 * dist[c]);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	scanf("%d", &n);

	init(n);

	for (int i = 0; i < n - 1; i++)
		{
			int x, y, c;

			scanf("%d%d%d", &x, &y, &c);

			g[x].push_back(MP(y, c));
			g[y].push_back(MP(x, c));
		}

	dfs(0);

	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		{
			int x, y;

			scanf("%d%d", &x, &y);

			printf("%d\n", query(x, y));
		}

	return 0;	
}
