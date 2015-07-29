#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g, gr, g1;

vector <bool> used;

vector <int> ord;

int n, m;

void dfs1(int v)
{
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs1(g[v][i]);

	ord.push_back(v);
}

void dfs2(int v, vector <int>& c)
{
	c.push_back(v);

	used[v] = true;

	for (size_t i = 0; i < gr[v].size(); i++)
		if (!used[gr[v][i]])
			dfs2(gr[v][i], c);
}

void init()
{
	g.resize(n);
	gr.resize(n);
	ord.reserve(n);
}

int main()
{
	freopen("o.in", "r", stdin);
	freopen("o.out", "w", stdout);

	cin >> n >> m;

	init();

	int x, y;
	
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			x--, y--;

			g[x].push_back(y);
			gr[y].push_back(x);
		}

	used.assign(n, false);

	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);

	used.assign(n, false);

	vector <int> ccc;

	vector <int> nmb(n, -1);

	int cnt = 0;

	for (int i = n - 1; i >= 0; i--)
		{
			if (!used[ord[i]])
				{
					dfs2(ord[i], ccc);

					for (size_t j = 0; j < ccc.size(); j++)
						nmb[ccc[j]] = cnt;

					cnt++;

					ccc.clear();
				}
		}

	vector <vector <bool> > is(cnt, vector <bool> (cnt, 0));

	int ans = 0;

	for (int i = 0; i < n; i++)
		{
			for (size_t j = 0; j < g[i].size(); j++)
				{
					int to = g[i][j];

					if (nmb[i] != nmb[to])
						{
							ans += (is[nmb[i]][nmb[to]] ^ 1);

							is[nmb[i]][nmb[to]] = true;
						}
				}
		}

	cout << ans;

	return 0;	
}
