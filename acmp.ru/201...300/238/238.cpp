#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define F first
#define S second
#define PII pair <int, int>
#define MP make_pair
#define INF 2000000000

int u[4] = {1, 0, 0, -1};
int d[4] = {0, 1, -1, 0};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	PII s;

	cin >> s.F >> s.S;

	vector <vector <int> > g(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				cin >> g[i][j];
				if (g[i][j] == 1)
					g[i][j] = -1;

				else
					g[i][j] = INF;
			}


  	int h;

  	cin >> h;

  	vector <pair <PII, PII> > gp(h);

  	for (int i = 0; i < h; i++)
  		{
  			cin >> gp[i].F.F >> gp[i].F.S >> gp[i].S.F >> gp[i].S.S;
  			gp[i].F.F--, gp[i].F.S--, gp[i].S.F--, gp[i].S.S --;
  		}

  	int ex;

  	cin >> ex;

  	vector <PII> exits(ex);

  	for (int i = 0; i < ex; i++)
  		{
  			cin >> exits[i].F >> exits[i].S;
  			exits[i].F--, exits[i].S--;
  		}

  	s.F--, s.S--;

  	g[s.F][s.S] = 1;

  	queue <PII> q;

  	q.push(s);

	while (!q.empty())
		{
			PII cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					PII tmp = cur;

					tmp.F += u[i];

					tmp.S += d[i];

					if (tmp.F >= 0 && tmp.F < n)
						{
							if (tmp.S >= 0 && tmp.S < m)
								{
									if (g[tmp.F][tmp.S] > g[cur.F][cur.S] + 1)
										{
											g[tmp.F][tmp.S] = g[cur.F][cur.S] + 1;
											q.push(tmp);
										}
								}
						}
				}

			for (int i = 0; i < h; i++)
				{
					if (gp[i].F == cur)
						{
							if (g[gp[i].S.F][gp[i].S.S] > g[cur.F][cur.S] + 1)
								{
									g[gp[i].S.F][gp[i].S.S] = g[cur.F][cur.S] + 1;
									q.push(gp[i].S);
								}
						}
				}
		}

 	int ans = INF;

   for (int i = 0; i < ex; i++)
 		ans = min(ans, g[exits[i].F][exits[i].S]);

 	if (ans < INF)
 		cout << ans;
 	else
 		cout << "Impossible";
}
