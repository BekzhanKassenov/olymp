#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector <vector <int> > g;

vector <int> deg;

vector <int> anc;

void dfs(int v, int pr = -1)
{
	anc[v] = pr;

	for (size_t i = 0; i < g[v].size(); i++)
		if (g[v][i] != pr)
			dfs(g[v][i], v);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	cin >> n;

	n++;

	g.resize(n);
	deg.resize(n);
	anc.resize(n, -1);

	int a, b;

	for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;

			a--, b--;

			g[a].push_back(b);
			g[b].push_back(a);

			deg[a]++, deg[b]++;
		}

	dfs(0);

	queue <int> q;

	vector <bool> used(n);

	for (int i = 0; i < n; i++)
		if (deg[i] == 1)
			{	
				q.push(i);
			}

	set <pair <int, int> > ans;

	while (!q.empty())
		{
			int v = q.front();

			q.pop();

			if (deg[v] == 1 && anc[v] != -1 && !used[anc[v]])
				{
					deg[v] = 0;
					used[anc[v]] = true;
					used[v] = true;

					ans.insert(make_pair(max(anc[v], v), min(anc[v], v)));

					for (size_t i = 0; i < g[anc[v]].size(); i++)
						{
							int to = g[anc[v]][i];

							if (to != v)
								{
									deg[to]--;

									if (deg[to] == 1 && !used[to])
										{
											q.push(to);
										}
								}
						}
				}
		}

	cout << ans.size() << endl;	

	for (set <pair <int, int> > :: iterator it = ans.begin(); it != ans.end(); it++)
		cout << it -> first + 1 << ' ' << it -> second + 1 << endl;

	return 0;	
}
