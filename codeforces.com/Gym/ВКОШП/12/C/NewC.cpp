#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > g;

vector <bool> used;

#define MOD (1000 * 1000 * 1000 + 7)

int dfs(int v, int gl, int p = -1)
{
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];

			if (!used[to])
				return dfs(to, gl + 1, v);

			else
				{
					if (to != p)
						return gl;
				}
		}
}

int main()
{
	freopen("fortification.in", "r", stdin);
	freopen("fortification.out", "w", stdout);

	int n, m;

	cin >> n >> m;

	g.resize(n);
	used.resize(n, 0);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			g[--x].push_back(--y);

			g[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		if (!used[i] && (g[i].size() == 1 || g[i].size() == 0))
			dfs(i, 1);

	int ans = 1;

	for (int i = 0; i < n; i++)
		if (!used[i])
			ans = (ans * dfs(i, 1)) % MOD;

	cout << ans;
	return 0;
}
