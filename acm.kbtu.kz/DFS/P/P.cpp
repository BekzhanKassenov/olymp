#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;

vector <vector <int> > g;

vector <int> ord;

vector <int> used;

void dfs(int v)
{
	used[v] = 1;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];

			if (!used[to])
				dfs(to);
			else
				{
					if (used[to] == 1)
						{
							cout << -1;
							exit(0);
						}
				}	
		}

	ord.push_back(v);
	used[v] = 2;
}

int main()
{
	freopen("p.in", "r", stdin);
	freopen("p.out", "w", stdout);

	int n, m;

	cin >> n >> m;

	g.resize(n);

	used.resize(n);

	ord.reserve(n);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			x--, y--;

			g[x].push_back(y);
		}

	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);

	for (int i = n - 1; i >= 0; i--)
		cout << ord[i] + 1 << ' ';

	return 0;	
}
