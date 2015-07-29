#include <iostream>
#include <cstdio>
#include <vector>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define INF (int)2e9

struct edge
{
	int cost;
	int to;

	edge() 
		{
			to = cost = 0;
		}

	edge(int a, int b)
		{
			to = a; 
			cost = b;
		}
};

vector <vector <edge> > g;

vector <int> dist, order, first, t, h;

vector <bool> used;

int q;

int n;

void init()
{
	g.resize(n);
	h.resize(n);
	first.resize(n);
	dist.resize(n);
	used.resize(n);
}

void dfs(int v, int gl)
{
	h[v] = gl;

	used[v] = true;

	order.push_back(v);

	first[v] = order.size() - 1;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].to;

			if (used[to])
				continue;

			dist[to] = dist[v] + g[v][i].cost;

			dfs(to, gl + 1);

			order.push_back(v);
		}
}

void build(int v, int l, int r)
{
	if (l > r)
		return;

	if (l == r)
		{
			t[v] = order[l];
			return;
		}

	int m = (l + r) >> 1;

	int tmp = v << 1;

	build(tmp, l, m);
	build(tmp + 1, m + 1, r);

	if (h[t[tmp]] < h[t[tmp + 1]])
		t[v] = t[tmp];
	else
		t[v] = t[tmp + 1];
}

void bbuild()
{
	q = order.size();

	t.resize(4 * q + 1);

	build(1, 0, q - 1);
}

int query(int v, int cur_l, int cur_r, int l, int r)
{
	if (cur_l > cur_r)
		return INF;

	//cout << cur_l << ' ' << cur_r << ' ' << l << ' ' << r << endl;

	if (cur_l == cur_r && cur_l >= l && cur_l <= r)
		return t[v];

	if (cur_l <= cur_r && (cur_l > r || cur_r < l))
		return INF; 

	if (cur_l >= l && cur_r <= r)
		return t[v];

	int m = (cur_l + cur_r) >> 1;

	int tmp = v << 1;

	int v1 = query(tmp, cur_l, m, l, r);

	int v2 = query(tmp + 1, m + 1, cur_r, l, r);

	if (v1 == INF)
		return v2;

	if (v2 == INF)
		return 	v1;

	if (h[v1] < h[v2])
		return v1;
	else
		return v2;

}

int get_ans(int v1, int v2)
{
	//puts("AGAIN");
	int v = query(1, 0, q - 1, min(first[v1], first[v2]), max(first[v1], first[v2]));
	return (dist[v1] + dist[v2] - 2 * dist[v]); 
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	init();

	for (int i = 0; i < n - 1; i++)
		{
			int a, b, c;

			scanf("%d%d%d", &a, &b, &c);

			g[a].push_back(edge(b, c));
			g[b].push_back(edge(a, c));
		}
	dfs(0, 0);

	bbuild();

	int m;
	
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		{
			int a, b;

			scanf("%d%d", &a, &b);

			printf("%d\n", get_ans(a, b));
		}

	return 0;

}
