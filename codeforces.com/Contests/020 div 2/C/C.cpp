#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define PII pair <long long, int>
#define F first
#define S second
#define MP make_pair
#define INF (long long)1e15

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector <vector <PII> > g(n);

	int x, y, cost;

	for (int i = 0; i < m; i++)
		{
		   cin >> x >> y >> cost;
			x--, y--;

			if (x != y)
				{
					g[x].push_back(MP(y, cost));
					g[y].push_back(MP(x, cost));
				}
		}

	priority_queue <PII, vector <PII>, greater <PII> > q;
	
	vector <long long> d(n, INF), pr(n, -1);

	d[0] = 0;

	q.push(MP(0, 0));

	while (!q.empty())
		{
			int v = q.top().S;
			long long c = q.top().F;

			q.pop();

			if (c != d[v])
				continue;
						
			for (size_t i = 0; i < g[v].size(); i++)
				{
					int to = g[v][i].F;
					int len = g[v][i].S;

					if (d[to] > d[v] + len)
						{
							d[to] = d[v] + len;
							pr[to] = v;
							q.push(MP(d[to], to));
						}
				}
		}

	if (d[n - 1] == INF)
		cout << -1;
	else
		{
			vector <int> ans;

			for (int pos = n - 1; pos != -1; pos = pr[pos])
				ans.push_back(pos);

			for (int i = (int)ans.size() - 1; i >= 0; i--)
				cout << ans[i] + 1 << ' ';
		}
}
