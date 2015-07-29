#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> tin, tout;

vector <vector <int> > g;

int timer = 0;

void init(int n)
{
	g.resize(n);

	tin.assign(n, 0);

	tout.assign(n, 0);
}

void dfs(int v)
{
	tin[v] = timer++;

	for (size_t i = 0; i < g[v].size(); i++)
		dfs(g[v][i]);

	tout[v] = timer++;
}

int main()
{
	freopen("i.in", "r", stdin);
	freopen("i.out", "w", stdout);

	int n;

	scanf("%d", &n);

	int pr = -1;

	int x;

	init(n);

	for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);

			if (x == 0)
				pr = i;
			else
				g[--x].push_back(i);
		}

	dfs(pr);

	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		{
			int x, y;

			scanf("%d%d", &x, &y);

			x--, y--;

			if (tin[x] < tin[y] && tout[x] > tout[y])
				puts("1");
			else
				puts("0");
		}

	return 0;	
}
