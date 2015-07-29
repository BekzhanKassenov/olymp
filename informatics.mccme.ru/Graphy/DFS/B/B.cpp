#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> color;

vector <vector <int> > g;

bool flag = true;

void dfs(int v, int c)
{
	color[v] = c;

	for (size_t i = 0; i < g[v].size(); i++)
		if (!color[g[v][i]])
			dfs(g[v][i], 3 - c);
		else
			if (color[g[v][i]] == color[v])
				flag = false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	g.resize(n);
	color.resize(n);

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			x--, y--;

			g[x].push_back(y);
			g[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		if (!color[i])
			dfs(i, 1);

	if (flag)
		{
			cout << "YES" << endl;

			for (int i = 0; i < n; i++)
				if (color[i] == 1)
					cout << i + 1 << ' ';

		}
	else
		cout << "NO";	
}
