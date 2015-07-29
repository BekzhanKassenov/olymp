#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector <vector <int> > dist;

int n, m, cx, cy, end_x, end_y;

int cnt;

int dx = 0, dy = 1;

vector <pair <int, int> > ans;

bool ok(int x, int y)
{
	if (x >= 0 && x < n)
		if (y >= 0 && y < m)
			return true;

	return false;
}

void turn(int &dx, int &dy)
{
	if (dx == 0 && dy == 1)
		{
			dy = 0, dx = 1;
			return;
		}

  	if (dx == 1 && dy == 0)
  		{
  			dx = 0, dy = -1;
  			return;
  		}

  	if (dx == 0 && dy == -1)
  		{
  			dx = -1, dy = 0;
  			return;
  		}

  	dx = 0, dy = 1;
}

void dfs(int x, int y, int prx = -1, int pry = -1)
{
	//cout << x << ' ' << y << endl;
	
	if (prx == -1)
		dist[x][y] = 0;
	else
		dist[x][y] = dist[prx][pry] + 1;
	
	if (x != end_x || y != end_y)
		{
			int tmpx = x + dx,
				 tmpy = y + dy;

			if (!ok(tmpx, tmpy) || dist[tmpx][tmpy] != -1)
				turn(dx, dy);

			dfs(x + dx, y + dy, x, y);
		}

	if (abs(dist[x][y] - dist[cx][cy]) <= cnt)
		ans.push_back(make_pair(x + 1, y + 1));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	cin >> end_x >> end_y;

	cin >> cx >> cy;

	cin >> cnt;

	cx--, cy--;

	end_x--, end_y--;

	dist.resize(n, vector <int> (m, -1));

	dfs(0, 0);

	for (int i = (int)ans.size() - 1; i >= 0; i--)
		cout << ans[i].first << ' ' << ans[i].second << endl;

	return 0;
}
