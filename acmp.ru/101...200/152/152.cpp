#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>

using namespace std;

vector <vector <int> > g;

vector <bool> used; 

vector <bool> inst;

void init(int n)
{
	g.resize(n);

	used.resize(n);

	inst.resize(n);
}

void dfs(int v)
{
	used[v] = true;

	inst[v] = true;

	for (int i = 0; i < (int) g[v].size(); i++)
		{
			int to = g[v][i];

			//cout << "v >> to " << v << ' ' << to << endl;

			if (!used[to])
				dfs(to);

			else
				{
					if (inst[to])
						{
							cout << "No" << endl;
							exit(0);
						}
				}
		}

   inst[v] = false;
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

			g[--x].push_back(--y);
		}

	for (int i = 0; i < n; i++)
		{
			if (!used[i])
				dfs(i);
		}

	cout << "Yes";
	return 0;
}
