#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int>  g[100];

vector <int> t;

vector <bool> used;

void dfs (int v)
{
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (!used[to])
				dfs(to);
		}
	t.push_back(v);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int n;
	cin >> n;
	used.assign(n, 0);
	for (int i = 0; i < n; i++)
		{
			int x = -1;
			while (cin >> x && x != 0)
				g[i].push_back(--x);
		}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
	for (int i = n - 1; i >= 0; i--)
		cout << t[i]+ 1 << ' ';
	return 0;
}
