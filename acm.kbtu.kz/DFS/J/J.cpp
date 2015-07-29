#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define PII pair <int, int>
#define MP make_pair

vector <vector <int> > g;

set <PII> s;

vector <int> tin, fup;

vector <bool> used;

int timer = 0;

void init(int n)
{
	g.resize(n);
	
	tin.resize(n);

	fup.resize(n);

	used.resize(n);
}

void dfs(int v, int p = -1)
{
	tin[v] = fup[v] = timer++;

	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];                              

			if (to == p)
				continue;

			if (used[to])
				fup[v] = min(fup[v], tin[to]);
			else
				{
					dfs(to, v);

					fup[v] = min(fup[v], fup[to]);

					if (fup[to] > tin[v])
						s.insert(MP(max(to, v), min(to, v)));
				}

		}
}

const int INF = (int)2e7;

void bfs(int s, vector <int>& dist)
{
	dist[s] = 0;

	queue <int> q;

	q.push(s);

	while (!q.empty())
		{
			int v = q.front();
			q.pop();

			for (size_t i = 0; i < g[v].size(); i++)
				{
					if (dist[g[v][i]] > dist[v] + 1)
						{
							q.push(g[v][i]);
							dist[g[v][i]] = dist[v] + 1;
						}
				}
		}
}

int main()
{
	freopen("j.in", "r", stdin);
	freopen("j.out", "w", stdout);

	int n, m;

	cin >> n >> m;

	init(n);

	map <PII, int> mpa;

	for (int i = 0; i < m; i++)
		{
			int x, y;

			cin >> x >> y;

			x--, y--;

			mpa[MP(max(x, y), min(x, y))] = i + 1;

			g[x].push_back(y);
			g[y].push_back(x);
		}

	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);

	set <int> ans;

	vector <int> dist1(n, INF), dist2(n, INF);

	bfs(0, dist1);
	bfs(n - 1, dist2);

	for (set <PII> :: iterator it = s.begin(); it != s.end(); it++)
		{
			if (dist1[it -> first] + dist2[it -> second] + 1 == dist1[n - 1] || dist1[it -> second] + dist2[it -> first] + 1 == dist1[n - 1])
				ans.insert(mpa[*it]);
		}

	cout << ans.size() << endl;

	for (set <int> :: iterator it = ans.begin(); it != ans.end(); it++)
		{                   
			cout << *it << ' ';
		}	

	return 0;
}
