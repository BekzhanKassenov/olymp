#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <bool> used;

int n;

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < (int)g[v].size(); i++)
		{
			int to = g[v][i];
			if (!used[to])
				dfs(to);
		}

}

int main()
{
	int m;
	cin >> n >> m;

	g.resize(n);

	used.assign(n, 0);

	int x, y;
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!used[i])
			{
				dfs(i);
				ans++;
			}
	cout << ans;;
	return 0;

}
