#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 33000;

const int INF = (int)2e9;

vector <vector <int> > g;

void bfs(vector <int>& d, int v)
{
	d.resize(MAXN, INF);

	d[v] = 0;

	queue <int> q;

	q.push(v);

	while (!q.empty())
		{
			int t = q.front();
			q.pop();

			for (size_t i = 0; i < g[t].size(); i++)
				{
					int to = g[t][i];

					if (d[t] + 1 < d[to])
						{
							d[to] = d[t] + 1;
							q.push(to);
						}
				}
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	g.resize(MAXN);

	set <int> s;

	for (int i = 0; i < n; i++)
		{
			int k;

			cin >> k;

			vector <int> tmp(k);

			for (int j = 0; j < k; j++)
				{
					cin >> tmp[j];
					s.insert(tmp[j]);
				}

			for (int j = 1; j < k; j++)
				{
					g[tmp[j]].push_back(tmp[j - 1]);
					g[tmp[j - 1]].push_back(tmp[j]);
				}

		}

 	vector <int> dist1, dist2;

 	int k;

 	cin >> k;

 	int a;

 	cin >> a;

 	if (k == 1)
 		{
 			for (int i = 0; i < MAXN; i++)
 				if (g[i].empty())
 					s.erase(i);

 			s.insert(a);
 		}
 	else
 		{
 			bfs(dist1, a);

 			s.erase(a);

 			for (int i = 1; i < k; i++)
 				{
 					int b;

 					cin >> b;

 					bfs(dist2, b);

 					set <int> s1;

 					for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
 						{
 							int to = *it;

 							if (dist1[to] == dist2[to] + dist1[b])
 								s1.insert(to);
 						}

 					s = s1;	
 					a = b;
 					dist1 = dist2;
 				}
 		}

 	for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
 		cout << *it << endl;

 	return 0;	
}
