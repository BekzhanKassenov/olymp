#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <assert.h>

using namespace std;

#define F first
#define S second

vector <vector <int> > g;

vector <bool> used;

vector <pair <int, int> > order;

vector <int> x;

int mgl = -1;

void init(int n)
{
	g.resize(n);
	used.resize(n, 0);

	order.reserve(n);
}

void dfs(int v, int gl = 0)
{
	order.push_back(make_pair(v, gl));

	mgl = max(gl, mgl);

	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			if (!used[g[v][i]])
				dfs(g[v][i], gl + 1);
		} 
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int q, w;

	init(n);

	for (int i = 0; i < n - 1; i++)
		{
			cin >> q >> w;

			q--, w--;

			g[q].push_back(w);
			g[w].push_back(q);
		}

	dfs(0);

	x.resize(mgl + 1, -1000);

	vector <pair <int, pair <int, int> > > ans(n);

	for (int i = 0; i < n; i++)
		{
			ans[i] = (make_pair(order[i].F, make_pair(x[order[i].S], 1000 - 2 * order[i].S)));
		   x[order[i].S] += 2;
		}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < n; i++)
		cout << ans[i].S.F << ' ' << ans[i].S.S << endl;

	return 0;
}
