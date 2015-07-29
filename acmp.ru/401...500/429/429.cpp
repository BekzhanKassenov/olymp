#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> val;

vector <vector <int> > g;

bool better(int h, int f, int s)
{
	if (s == 2)
		return true;

	if (h == 1)
		{
			if (s == 1)
				return false;

			if (s == 0)
				{
					if (f == 1)
						return true;

					return false;
				}

			if (s == -1)
				return true;
		}

	if (h == 0)
		{
			if (s == -1)
				return false;

			if (s == 0)
				{
					if (f == -1)
						return true;

					return false;
				}

			if (s == 1)
				return true;
		}
}

void dfs(int v, int h = 1)
{
	for (size_t i = 0; i < g[v].size(); i++)
		{
			dfs(g[v][i], h ^ 1);

			if (better(h, val[g[v][i]], val[v]))
				val[v] = val[g[v][i]];
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	val.resize(n, 2);
	g.resize(n);

	for (int i = 1; i <= n - 1; i++)
		{
			char c;

			cin >> c;

			int pr, vl = 2;

			cin >> pr;

			if (c == 'L')
				cin >> vl;

			g[pr - 1].push_back(i);
			val[i] = vl;
		}              

	dfs(0);

	if (val[0] == 1)
		cout << "+1";
	else
		cout << val[0];	

	return 0;
}
