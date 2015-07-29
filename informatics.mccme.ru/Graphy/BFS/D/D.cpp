#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define PII pair <int, int>

int u[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int t[] = { 1,  2, 2, 1,-1,-2, -2, -1};

bool used[8][8];

bool test(PII p, int i)
{
	if (p.F + u[i] >= 0 && p.F + u[i] < 8)
		if (p.S + t[i] >= 0 && p.S + t[i] < 8)
			if (!used[p.F + u[i]][p.S + t[i]])
				return true;
	return false;
}

vector <vector <int> > bfs(int x, int y)
{
	vector <vector <int> > d(8, vector <int> (8, 1000));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			used[i][j] = false;
	queue <PII> q;
	q.push(MP(x,y));
	used[x][y] = true;
	d[x][y] = 0;
	while (!q.empty())
		{
			PII p = q.front();
			q.pop();
			for (int i = 0; i < 8; i++)
				{
					if (test(p ,i))
						{
							int x = p.F + u[i];
							int y = p.S + t[i];
							q.push(MP(x,y));
							used[x][y] = true;
							d[x][y] = d[p.F][p.S] + 1; 
						}
				}
		}
   return d;
}

int main()
{
	int x1, y1, x2, y2;
	{
	char a,b;
	cin >> a >> b;
	x1 = a - 'a';
	y1 = b - '0' - 1;
	cin >> a >> b;
	x2 = a - 'a';
	y2 = b - '0' - 1;
	}
	vector <vector <int> > a, b;
	a = bfs(x1, y1);
	b = bfs(x2, y2);
	int ans = 1000;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (a[i][j] == b[i][j])
				ans = min(ans, a[i][j]);
	if (ans < 1000)
		cout << ans;
	else
		cout << -1;
	return 0;
}
