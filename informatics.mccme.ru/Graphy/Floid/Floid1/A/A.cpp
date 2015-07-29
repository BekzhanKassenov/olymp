#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define INF 2000000000

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, s, t;
	cin >> n >> s >> t;
	s--;
	t--;
	vector <vector <int> > g(n, vector <int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	vector <int> d(n ,INF);
	d[s] = 0;
	set < pair < int, int > > q;
	q.insert(make_pair(0,s));
	while (!q.empty())
		{
			int v = q.begin() -> second;
			q.erase(q.begin());
			for (int i = 0; i < n; i++)
				if (g[v][i] != -1 && i != v && d[i] > d[v] + g[v][i])
					{
						q.erase(make_pair(d[i], i));
						d[i] = d[v] + g[v][i];
						q.insert(make_pair(d[i],i));
					}
		}
	if (d[t] < INF)
		cout << d[t];
	else
		cout << -1;
	return 0;
}
