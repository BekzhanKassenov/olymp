#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> tin, fup;

vector <vector <int> > g;

vector <bool> used;

vector <bool> is;

int timer = 0;

int ans = 0;

void dfs(int v, int p = -1)
{
	tin[v] = fup[v] = timer++;

	used[v] = true;

	int c = 0;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];

			if (to == p)
				continue;

			if (used[to])
				{
					fup[v] = min(fup[v], tin[to]);
				}
			else
				{
					dfs(to, v);

					fup[v] = min(fup[v], fup[to]);

					if (fup[to] >= tin[v] && p != -1)
						is[v] = true;
					c++;
				}	
		}

	if (p == -1 && c > 1)
		is[v] = true;

	ans += is[v];
}

void init(int n)
{
	g.resize(n);
	
	used.resize(n);

	tin.resize(n);

	fup.resize(n);

	is.resize(n);
}

int main()
{
	freopen("m.in", "r", stdin);
	freopen("m.out", "w", stdout);

	int n, m;

	scanf("%d%d", &n, &m);

	init(n);

	int a, b;

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);

			a--, b--;

			g[a].push_back(b);
			g[b].push_back(a);
		}

	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);

	printf("%d\n", ans);

	for (int i = 0; i < n; i++)
		if (is[i])
			printf("%d\n", i + 1);
}
