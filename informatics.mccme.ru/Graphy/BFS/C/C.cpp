#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair <int, int>

vector <vector <int> > g, d;

int n,m;

void init()
{
	g.assign(n, vector <int> (m));
	d.assign(n, vector <int> (m, 100000));
}

bool check(int x, int y)
{
	if (x < n && x>=0)
		if (y < m && y >= 0)
			return true;
	return false;
}

void bfs(int x, int y)
{
	d[x][y] = 0;
	queue <pii> q;
	q.push(MP(x,y));
	while (!q.empty())
		{
			pii p = q.front();
			q.pop();
			if (check(p.F - 1, p.S))
				{
					if (d[p.F - 1][p.S] > d[p.F][p.S] + 1)
						{
							d[p.F - 1][p.S] = d[p.F][p.S] + 1;
							q.push(MP(p.F - 1, p.S));
						}
				}
			if (check(p.F + 1, p.S))
				{
					if (d[p.F + 1][p.S] > d[p.F][p.S] + 1)
						{
							d[p.F + 1][p.S] = d[p.F][p.S] + 1;
							q.push(MP(p.F + 1, p.S));
						}
				}
			if (check(p.F, p.S - 1))
				{
					if (d[p.F][p.S - 1] > d[p.F][p.S] + 1)
						{
							d[p.F][p.S - 1] = d[p.F][p.S] + 1;
							q.push(MP(p.F, p.S - 1));
						}
				}
			if (check(p.F, p.S + 1))
				{
					if (d[p.F][p.S + 1] > d[p.F][p.S] + 1)
						{
							d[p.F][p.S + 1] = d[p.F][p.S] + 1;
							q.push(MP(p.F, p.S + 1));
						}
				}

		}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j])
				bfs(i,j);

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
		   	cout << d[i][j] << ' ';
		   cout << endl;
		}
	return 0;
}

