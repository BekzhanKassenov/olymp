#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> order;

vector <vector <int> > g, g1;

vector <bool> used;

void init(int n)
{
	order.reserve(n);
	g.resize(n);
	g1.resize(n);
	used.assign(n, false);
}

void dfs(int v, vector <vector <int> >& gr, vector <int>& a)
{
	used[v] = true;

	for (size_t i = 0; i < gr[v].size(); i++)
		if (!used[gr[v][i]])
			dfs(gr[v][i], gr, a);

	a.push_back(v);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	init(n);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			x--, y--;

			g[x].push_back(y);
			g1[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i, g, order);

	vector <int> ans(n);

	used.assign(n, false);

	int cnt = 0;

	vector <int> cmp;

	for (int i = n - 1; i >= 0; i--)
		{
			if (!used[order[i]])
				{
					dfs(order[i], g1, cmp);
					
					cnt++;
					
					for (size_t j = 0; j < cmp.size(); j++)
						{
							ans[cmp[j]] = cnt;
						}    

					cmp.clear();	
				}
		}

   	cout << cnt << endl;

   	for (int i = 0; i < n; i++)
   		cout << ans[i] << ' ';
}
