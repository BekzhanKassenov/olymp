#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	vector <vector <int> > g(n, vector <int> (n, INF));

	int x, y;

	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			y--, x--;

			int val;

			cin >> val;

			g[x][y] = val;
		}

	queue <int> q;

	vector <double> d(n, INF);

	d[0] = 0;

	q.push(0);

	while (!q.empty())
		{
			int v = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
				{
					if (g[v][i] < INF)
						{
							if (d[i] > d[v] + g[v][i])
								{
									q.push(i);
									d[i] = d[v] + g[v][i];
								}
						}
				}
		}

	for (int i = 0; i < n; i++)
		if (d[i] < INF)
			cout << d[i] << ' ';
		else
			cout << 30000 << ' ';
				
	return 0;
}
