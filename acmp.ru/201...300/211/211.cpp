#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define INF 2000000000

int n, m;

int bfs(int x, int y, int _x, int _y, vector <vector <int> > &dist)
{
	queue <PII> q;
	q.push(MP(x, y));

	dist[x][y] = 0;

	while (!q.empty())
		{
			PII cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					PII tmp = cur;
					tmp.F += u[i];
					tmp.S += d[i];

					if (tmp.F == _x && tmp.S == _y)
						{
							return dist[cur.F][cur.S] + 1;
						}

					if (tmp.F >= 0 && tmp.F <= n + 1)
						{
							if (tmp.S >= 0 && tmp.S <= m + 1)
								{
									if (dist[tmp.F][tmp.S] > dist[cur.F][cur.S] + 1 && dist[tmp.F][tmp.S] != -1)
										{
											dist[tmp.F][tmp.S] = dist[cur.F][cur.S] + 1;
											q.push(tmp);
										}
								}
						}
				}
		}
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> m >> n;

	vector <vector <int> > d(n + 2, vector <int> (m + 2, INF));

	char c;

	for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				{
					cin >> c;
					
					if (c == 'X')
						d[i][j] = -1;
				} 
		}

	int x, y, _x, _y;

	cin >> x >> y >> _x >> _y;

	while (x != 0 || y != 0 || _x != 0 || _y != 0)
		{
			vector <vector <int> > tmp(d);

			int ans = bfs(y, x, _y, _x, tmp);

			if (ans != -1)
				{
					cout << ans << endl;
				}
			else
				{
					cout << 0 << endl;;
				}

			cin >> x >> y >> _x >> _y;
		} 
}

