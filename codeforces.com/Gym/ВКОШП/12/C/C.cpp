#include <cstdio>
#include <vector>

using namespace std;

#define MOD 1000000007

vector <vector <int> > g;

vector <bool> used;

int dfs(int v, int gl, int p = -1)
{
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (!used[to])
				{
					return dfs(to, gl + 1, v); 
				}
			else
				if (to != p)
					return gl;
		}
	return 1;
}

void init(int n)
{
	g.resize(n + 1);
	used.assign(n + 1, 0);
}

int main()
{
	freopen("fortification.in", "r", stdin);
	freopen("fortification.out", "w", stdout);

	int n, m;

	scanf("%d%d", &n, &m);

	init(n);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);

			g[--x].push_back(--y);
			g[y].push_back(x);
		}

	int ans = 1;

	for (int i = 0; i < n; i++)
		if (!used[i] && (g[i].size() == 1 || g[i].size() == 0))
			dfs(i, 1);

	for (int i = 0; i < n; i++)
		{
			if (!used[i])
				ans = (ans * dfs(i, 1)) % MOD;
		}

	printf("%d", ans);
	return 0;
}
   