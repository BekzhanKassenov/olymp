#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <bool> used;

int n, m;

void dfs(int v)
{
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			if (!used[g[v][i]])
				dfs(g[v][i]);
		}
}

int main()
{
	cin >> n >> m;

	g.resize(n);

	used.resize(n);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			g[--x].push_back(--y);
			g[y].push_back(x);
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				dfs(i);
				ans++;
			}

  	cout << ans;
  	return 0;


}
