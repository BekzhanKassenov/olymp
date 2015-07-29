#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define PII pair <int, int>
#define MP make_pair

vector <vector <int> > g;

set <PII> s;

vector <int> tin, fup;

vector <bool> used;

int timer = 0;

void init(int n)
{
	g.resize(n);
	
	tin.resize(n);

	fup.resize(n);

	used.resize(n);
}

void dfs(int v, int p = -1)
{
	tin[v] = fup[v] = timer++;

	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];                              

			if (to == p)
				continue;

			if (used[to])
				fup[v] = min(fup[v], tin[to]);
			else
				{
					dfs(to, v);

					fup[v] = min(fup[v], fup[to]);

					if (fup[to] > tin[v])
						s.insert(MP(max(to, v), min(to, v)));
				}

		}
}

int main()
{
	freopen("k.in", "r", stdin);
	freopen("k.out", "w", stdout);

	int n, m;

	cin >> n >> m;

	init(n);

	vector <PII> vec(m);

	for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			x--, y--;

			vec[i] = MP(max(x, y), min(x, y));

			g[x].push_back(y);
			g[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);

   	vector <int> ans;

	for (int i = 0; i < m; i++)
		if (s.find(vec[i]) != s.end())
			ans.push_back(i + 1);

	cout << ans.size() << endl;

	for (size_t i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}
