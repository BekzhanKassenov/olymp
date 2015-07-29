#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = (int)2e9;

struct coord
{
	int x, y, z;

	coord() {}

	coord(int x, int y, int z) : x(x), y(y), z(z) {}
};

vector <vector <vector <int> > > a;

int dx[5] = {0, 0,  0,  0, 1};
int dy[5] = {0, 1, -1,  0, 0};
int dz[5] = {1, 0,  0, -1, 0};

int h, m, n;

bool ok(coord c)
{
	if (c.x >= 0 && c.x < h)
		if (c.y >= 0 && c.y < n)
			if (c.z >= 0 && c.z < m)
				if (a[c.x][c.y][c.z] == 0)
					return true;

 	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> h >> n >> m;

	a.assign(h, vector <vector <int> > (n, vector <int> (m)));

	vector <vector <vector <int> > > dist(h, vector <vector <int> > (n, vector <int> (m, INF)));

	coord beg, en;

	for (int i = 0; i < h; i++)
		{
			char c;

			for (int j = 0; j < n; j++)
				for (int k = 0; k < m; k++)
					{
						cin >> c;

						if (c == '.')
							a[i][j][k] = 0;

						if (c == '1')
							{
								beg = coord(i, j, k);
								a[i][j][k] = 0;
							}

						if (c == '2')
							{
								en = coord(i, j, k);
								a[i][j][k] = 0;
							}	

						if (c == 'o')
							{
								a[i][j][k] = 1;
							}         
					}
		}

 	dist[beg.x][beg.y][beg.z] = 0;

 	queue <coord> q;

 	q.push(beg);

 	while (!q.empty())
 		{
 			coord cur = q.front();
 			q.pop();

 			for (int i = 0; i < 5; i++)
 				{
 					coord tmp = coord(cur.x + dx[i], cur.y + dy[i], cur.z + dz[i]);

 					if (ok(tmp))
 						{
 							if (dist[tmp.x][tmp.y][tmp.z] > dist[cur.x][cur.y][cur.z] + 1)
 								{
 									q.push(tmp);
 									dist[tmp.x][tmp.y][tmp.z] = dist[cur.x][cur.y][cur.z] + 1;
 								}
 						}
 				}
 		}

  	cout << 5 * dist[en.x][en.y][en.z];
}
