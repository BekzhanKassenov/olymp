#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = (int)2e9;

struct edge
{
	int cost;

	int to, tim;

	edge(int to, int tim, int cost) : to(to), tim(tim), cost(cost) {}
};

vector <vector <edge> > g;

int n;

int deikstra(int k)
{
	priority_queue <pair <int, int> > q;

	//cout << k << ": ";

	vector <int> dist(n, INF);

	dist[0] = 0;

	q.push(make_pair(0, 0));

	while (!q.empty())
		{
			int v = q.top().second;

			int d = -q.top().first;

			q.pop();

			if (d != dist[v])
				continue;

			for (size_t i = 0; i < g[v].size(); i++)
				{
					int to = g[v][i].to;
					int cost = g[v][i].cost;

					if (cost >= k && dist[to] > dist[v] + g[v][i].tim)
						{
							dist[to] = dist[v] + g[v][i].tim;
							q.push(make_pair(-dist[to], to));
					  		//cout << cost << ' ' ;
					  	}
				}
		}
		               
	//cout << dist[n - 1] << endl;
	return dist[n - 1];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	g.resize(n);

	int m;

	cin >> m;

	for (int i = 0; i < m; i++)
		{
			int a, b, ti; 
			int cost;

			cin >> a >> b >> ti >> cost;

			a--, b--;

			g[a].push_back(edge(b, ti, cost));
			g[b].push_back(edge(a, ti, cost));
		}

	int l = -1, r = 10000001;

	int lim = 1440;

	int ans = 0;

	while (r - l > 1)
		{
			int m = (l + r) >> 1;
			
			//cout << l << ' ' << r << endl;

			int cnt = 3000000 + m * 100;

			if (deikstra(cnt) <= lim)
				{
					ans = max(ans, m);
					l = m;
				}
			else
				r = m;
		}

	cout << ans;
}
