#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int inf = 1000000000;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <int> cost(n);
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	int x,y;
	int m;
	cin >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; i++)
		{	
			cin >> x >> y;
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	set <pair <int, int> > q;
	vector <int> d(n, inf);
	d[0] = 0;
	q.insert(make_pair(0, 0));
	while (!q.empty())	
		{
			int v = q.begin() -> second;
			q.erase(q.begin());
			for (int j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j];
					if (d[to] > d[v] + cost[v])
						{
							q.erase(make_pair(d[to],to));
							d[to] = d[v] + cost[v];
							q.insert(make_pair(d[to],to));
						}
				}
		}
  	if (d[n-1] < inf)
  		cout << d[n-1];
  	else
  		cout << -1;
}
