#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <int> sz;

vector <bool> used;

vector <int> h;

int n;

struct edge
{
	int from, to, cost;
};

void init()
{
	g.resize(n);
	sz.resize(n);
	used.resize(n);
	h.resize(n);
}

istream& operator >> (istream& c, edge& e)
{
	c >> e.from >> e.to >> e.cost;
	
	e.from--, e.to--;

	return c;
}

void dfs(int v, int gl = 0)
{
	sz[v] = 1;

	used[v] = true;

	h[v] = gl;

	for (size_t i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			{
				dfs(g[v][i], gl + 1);
				sz[v] += sz[g[v][i]];
			}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	init();
	
	vector <edge> a(n - 1);

	for (int i = 0; i < n - 1; i++)
		{
			cin >> a[i];
			g[a[i].from].push_back(a[i].to);
			g[a[i].to].push_back(a[i].from);
		}

	dfs(0);

	long long ans = 0;

	for (int i = 0; i < n - 1; i++)
		{
			if (h[a[i].to] > h[a[i].from])
				swap(a[i].to, a[i].from);

			//cout << a[i].from + 1 << ' ' << h[a[i].from] << ' ' << sz[a[i].from] << endl;

			ans += a[i].cost * 1ll * sz[a[i].from] * 1ll * (n - sz[a[i].from]);
		}

	printf("%.5lf", double(ans * 2) / double(n * 1ll * (n - 1)));

	return 0;	
}
