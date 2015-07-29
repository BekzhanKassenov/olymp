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
	int n, s, f;
	cin >> n >> s >> f;
	vector <vector <int> > g(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0;  j < n; j++)
			cin >> g[i][j];
	vector <int> d(n, inf);
	s--;
	f--;
	d[s] = 0;
	set<pair <int, int> > q;
	q.insert(make_pair(0, s));
	while (!q.empty())
		{
			int v = q.begin() -> second;
			q.erase(q.begin());
			for (int j = 0; j < n; j++)
				{
					if (g[v][j] > 0)
						{
							if (d[j] > d[v] + g[v][j])
								{
									q.erase(make_pair(d[j], j));
									d[j] = d[v] + g[v][j];
									q.insert(make_pair(d[j], j));
								}
						}
				}
		}
	if (d[f]!=inf)
		cout << d[f];
	else
		cout << -1;
		return 0;
}
