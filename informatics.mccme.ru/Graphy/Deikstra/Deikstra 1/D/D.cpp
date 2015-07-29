#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct edge
{
	int to;
	int vremya;
	int val;
};

int n, m;

const int inf = 1000000000;

int ans = 0;

vector <vector <edge> > g;

edge make_edge(int to, int vr, int val)
{
	edge ans;
	ans.to = to;
	ans.vremya = vr;
	ans.val = val;
	return ans;
}

int deikstra(int k)
{
	vector <int> d(n, inf);
	vector <bool> used(n, false);
	d[0] = 0;
	for (int i = 0; i < n; i++)
		{
			int v = -1;
			for (int j = 0; j < n; j++)
				if (!used[j] && (v == -1 || d[j] < d[v]))
					v = j;
			used[v] = true;
			for (size_t j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j].to;
					if (d[to] > d[v] + g[v][j].vremya && g[v][j].val >= k)
						d[to] = d[v] + g[v][j].vremya;
				}
		}
	return d[n-1];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	g.resize(n);
	int x, y, cost, val;
	for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> cost >> val;
			x--;
			y--;
			val -= 3000000;
			val /= 100;
			g[x].push_back(make_edge(y, cost, val));
			g[y].push_back(make_edge(x, cost, val));
		}
	int l = 0, r = 10000000;
	while (l < r)
		{
			int m = (l + r) / 2;
			int k = deikstra(m);
			if (k > 1440)
				r = m;
			else
				{
					ans = max (ans, m);
					l = m + 1;
				}
		}  
	cout << ans;
	return 0;
}
