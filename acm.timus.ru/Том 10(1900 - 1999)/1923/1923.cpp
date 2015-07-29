#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

vector <vector <int> > g;

int n, m;

int d[4] = {1, -1, 0,  0};
int u[4] = {0,  0, 1, -1};

bool check(int a, int b)
{
	if (a >= 0 && a < n)
		if (b >= 0 && b < m)
			return true;

	return false;
}

void bfs(int x, int y, int cl)
{
	queue <PII> q;

	int cl1 = g[x][y];

	q.push(MP(x, y));

	vector <vector <bool> > used(n, vector <bool> (m));

	used[x][y] = 1;

	while (!q.empty())
		{
			PII tmp = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					int xz = tmp.F + d[i];
					int yz = tmp.S + u[i];

					if (check(xz, yz))
						{
							if (g[xz][yz] == cl1 && !used[xz][yz])
								{
									g[xz][yz] = cl1;
									used[xz][yz] = true;
									q.push(MP(xz,yz));
								}
						}
				}
		}

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					for (int k = 0; k < 4; k++)
						{
							int xz = i + d[k];
							int yz = j + u[k];

							if(check(xz, yz) && g[xz][yz] == cl1 && used[xz][yz])
								{
									q.push(MP(i, j));
									break;
								}
						}
				}
		}

	while (!q.empty())
		{
			PII tmp = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
				{
					int xz = tmp.F + d[i];
					int yz = tmp.S + u[i];

					if (check(xz, yz))
						{
							if (g[xz][yz] == cl && !used[xz][yz])
								{
									g[xz][yz] = cl;
									used[xz][yz] = true;
									q.push(MP(xz,yz));
								}
						}
				}
		}

}

int s(int x, int y)
{
	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += (g[i][j] == g[x][y]);

  	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	char c;

	cin >> n >> m;

	g.assign(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					cin >> c;
					g[i][j] = c - '0';
				}
		}

	int l;

	cin >> l;

	int a1 = n - 1, a2 = 0;

	for (int i = 0; i < l; i++)
		{
			int tmp;
			cin >> tmp;

			bfs(a1, a2, tmp);

			if (a2 == 0)
				{
					a1 = 0;
					a2 = m - 1;
				}
			else
				{
					a1 = n - 1;
					a2 = 0;
				}
		}

 	int ans1 = s(n - 1, 0);

 	int ans2 = s(0, m - 1);

 	cout << ans1 << endl << ans2;
 	
 	return 0;
}