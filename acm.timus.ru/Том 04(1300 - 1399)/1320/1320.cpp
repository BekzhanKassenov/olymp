#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int g[1010][1010], degree[1010];

bool used[1010], here[1010];

void dfs(int v, vector <int>& comp)
{
	used[v] = true;

	comp.push_back(v);

	for (int i = 0; i < 1010; i++)
		{
			if (g[v][i] && !used[i])
				dfs(i, comp);
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int x, y;

	while (scanf("%d%d", &x, &y) == 2)
		{
			x--, y--;

			here[x] = here[y] = true;

			degree[x]++, degree[y]++;

			g[x][y] = g[y][x] = 1;
		}

	vector <int> comp;

	bool flag = true;
		
	for (int i = 0; i < 1010; i++)
		if (!used[i] && here[i])
			{
				comp.clear();
				dfs(i, comp);

				int ans = 0;

				for (size_t j = 0; j < comp.size(); j++)
					ans += degree[comp[j]];

				ans >>= 1;

				flag &= ((ans & 1) ^ 1);
			}

	cout << (flag ? 1 : 0);
	return 0;
}
