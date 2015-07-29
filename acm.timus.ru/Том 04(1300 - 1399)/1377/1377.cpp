#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;

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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	int _x, _y, x1, y1;

	cin >> _x >> _y >> x1 >> y1;

	_x--, _y--, x1--, y1--;

	int x = 0, y = 0;

	int dx = 0, dy = 1;

	vector <vector <int> > used(n, vector <int> (m));
	     
	int k = 0;
	
	int cnt = 0;

	while (k <= n * m)
		{
			used[x][y] = true;
			
			k++, cnt++;

			if (x == _x && y == _y || x == x1 && y == y1)
				{
					if (cnt == k)
						cnt = 0;
					else
						break;	
				}

			int cur_x = x + dx;

			int cur_y = y + dy;

			if (!ok(cur_x, cur_y) || used[cur_x][cur_y])
				{
					turn(dx, dy);
				}	

			x += dx;
			y += dy;	
		}

	cout << cnt;
}
