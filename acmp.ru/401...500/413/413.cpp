#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
vector <vector <int> > g;
vector <vector <int> > used;

void dfs(int i, int j)
{
	used[i][j] = true;
	if (i > 0)
		{
			if (g[i - 1][j] && !used[i - 1][j])
				dfs(i - 1, j);
		}
	if (i < n - 1)
		{
			if (g[i + 1][j] && !used[i + 1][j])
				dfs(i + 1, j);
		}
	if (j > 0)
		{
			if (g[i][j - 1] && !used[i][j - 1])
				dfs(i,j - 1);
		}
	if (j < m - 1)
		{
			if (g[i][j + 1] && !used[i][j + 1])
				dfs(i, j +  1);
		}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++)
		{
			g[i].resize(m);
			used[i].assign(m,false);
		}
	char c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				cin >> c;
				if (c == '#') g[i][j] = true;
				else g[i][j] = false;
			}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!used[i][j] && g[i][j])
				{
					dfs(i,j);
					ans++;
				}
	cout << ans;
	return 0;
}
