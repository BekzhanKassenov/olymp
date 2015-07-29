#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;

vector <vector <int> > g;

vector <int> used;

vector <int> order;

bool can = true;

void dfs(int v)
{
	used[v] = 1;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			if (!used[g[v][i]])
				dfs(g[v][i]);
			else
				if (used[g[v][i]] == 1)
					can = false;	
		}

	order.push_back(v);
	used[v] = 2;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m;

	cin >> n >> m;

	g.resize(n);
	used.resize(n);
	order.reserve(n);

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

   	if (can)
   		{
   			cout << "Yes" << endl;

   			for (int i = n - 1; i >= 0; i--)
   				cout << order[i] + 1 << ' ';
   		}
   	else
   		cout << "No";

   	return 0;	
}
