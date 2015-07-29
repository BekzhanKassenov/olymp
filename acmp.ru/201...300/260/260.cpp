#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>

using namespace std;

#define INF 2000000000

struct edge
{
	int to, cost;
	edge(int a, int b)
		{
			to = a;
			cost = b;
		}
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, m, k, capital;
	cin >> n >> m >> k >> capital;
	vector <int> cities(k);
	for (int i = 0; i < k; i++)
		cin >> cities[i];
	vector <vector <edge> > g(n);
	int x, y, val;
	for (int i = 0; i < m; i++)	
		{
			cin >> x >> y >> val;
			g[--x].push_back(edge(--y, val));
			g[y].push_back(edge(x, val));
		}
	set <pair <int, int> > q;
	vector <int> d(n, INF);
	d[--capital] = 0;
	q.insert(make_pair(0,capital));
	while (!q.empty())
		{
			int v = q.begin() -> second;
			q.erase(q.begin());
			for (int j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j].to;
					if (d[to] > d[v] + g[v][j].cost)
						{
							q.erase(make_pair(d[to],to));
							d[to] = d[v] + g[v][j].cost;
							q.insert(make_pair(d[to],to));
						}
				}
		}
	vector <pair <int, int> >ans;
	for (int i = 0; i < k; i++)
		ans.push_back(make_pair(d[cities[i] - 1], cities[i]));
   sort(ans.begin(), ans.end());
   for (int i = 0; i < k; i++)
   	cout << ans[i].second << ' ' << ans[i].first << endl;
   return 0;
}
