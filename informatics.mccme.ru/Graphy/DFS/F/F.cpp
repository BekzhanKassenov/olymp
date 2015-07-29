#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <bool> used;

void dfs(int v, vector <int>& comp)
{
	used[v] = true;

	comp.push_back(v);

	for (size_t i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs(g[v][i], comp);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	g.resize(n);
	used.resize(n);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			x--, y--;

			g[x].push_back(y);
			g[y].push_back(x);
		}

	vector <int> comp;

	vector <vector <int> > ans;

	for (int i = 0; i < n; i++)
		{
			if (!used[i])
				{
					dfs(i, comp);
					ans.push_back(comp);
					comp.clear();
				}
		}	

	cout << ans.size() << endl;

	for (size_t i = 0; i < ans.size(); i++)
		{
			cout << ans[i].size() << endl;
			
			for (size_t j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] + 1 << ' ';

			cout << endl;	
		}

	return 0;	
}
