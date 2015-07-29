#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) (x) * (x)

struct planet
{
	int x, y, z;

	int r;

	planet() {}

	planet(int x, int y, int z, int r) : x(x), y(y), z(z), r(r) {}

	bool insersects(planet a)
		{
			int dist = sqr(x - a.x) + sqr(y - a.y) + sqr(z - a.z);

			int d = sqr(r + a.r);

			return (dist < d);
		}
};

vector <planet> a;

vector <vector <int> > g;

vector <bool> used;

void dfs(int v, vector <int> &comp)
{
	used[v] = true;

	comp.push_back(v);

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];

			if (!used[to])
				dfs(to, comp);
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	a.resize(n);

	g.resize(n);

	used.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (a[i].insersects(a[j]))
						{
							g[i].push_back(j);
							g[j].push_back(i);
						}
				}
		}

	vector <int> cmp;

	for (int i = 0; i < n; i++)
		{
			if (!used[i])
				{
					cmp.clear();

					dfs(i, cmp);

					sort(cmp.begin(), cmp.end());

					int cnt = cmp.size();

					for (int i = 0; i < cnt; i++)
						{
							cout << cmp[i];

							if (i != cnt - 1)
								cout << ", ";
							else
								cout << endl;	
						}
				}
		}
}
