#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int dist[30][30][10][5];

int a[30][30];

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, -1,  0, 1};

int n, m, k;

struct state
{ 
	int x, y;

	int turns, dir;

	state() : x(0), y(0), turns(0), dir(0) {}

	state(int x, int y, int turns, int dir) : x(x), y(y), turns(turns), dir(dir) {}

	bool not_used() const
		{
			return (dist[x][y][turns][dir] == -1);
		}

	void set(int d) const
		{
			dist[x][y][turns][dir] = d;
		}

	bool ok() const
		{
			return (x >= 0 && x < n && y >= 0 && y < m && turns <= k && a[x][y] == 0);
		}

	int get() const
		{
			if (ok())
				return dist[x][y][turns][dir];
			else
				return -1;
		}
};

bool relax(const state& current, int tmp_dir, int cnt, state& tmp)
{
	tmp = current;

	tmp.dir = tmp_dir;

	tmp.x += dx[tmp_dir];
	tmp.y += dy[tmp_dir];

	tmp.turns += cnt;

	if (tmp.ok() && (tmp.not_used() || (tmp.get() > current.get() + 1)))
		{
			tmp.set(current.get() + 1);
			return true;
		}

	return false;	
}

ostream& operator << (ostream& c, const state& s)
{
	c << s.x << ' ' << s.y << ' ' << s.turns << ' ' << s.dir;

	if (s.ok())
		c << ' ' << dist[s.x][s.y][s.turns][s.dir];

	return c;	
}

void bfs(state st)
{
	queue <state> q;

	q.push(st);

	st.set(0);

	while (!q.empty())
		{
			state current = q.front();

			//cout << current << endl;

			q.pop();

			int tmp_dir = (current.dir - 1 + 4) % 4;

			state tmp = current;

			if (relax(current, tmp_dir, 0, tmp))
				q.push(tmp);

			tmp_dir = (current.dir + 1) % 4;

			if (relax(current, tmp_dir, 1, tmp))
				q.push(tmp);

			if (relax(current, current.dir, 0, tmp))
				q.push(tmp);
		}

   //cout << endl;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> k >> n >> m;

	memset(dist, -1, sizeof dist);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int xs = 0, ys = 0, xe = 0, ye = 0;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					if (a[i][j] == 2)
						{
							a[i][j] = 0;
							xs = i, ys = j;
						}

				    if (a[i][j] == 3)
				    	{
				    		a[i][j] = 0;
				    		xe = i, ye = j;
				    	} 
				}
		}

	for (int i = 0; i < 4; i++)
		{
			state start(xs, ys, 0, i);

			bfs(start);
	   	}

	int ans = (int)2e9;

	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= k; j++)
				if (dist[xe][ye][j][i] != -1)
					ans = min(ans, dist[xe][ye][j][i]);
		}

	if (ans != (int)2e9)
		cout << ans;
	else
		cout << -1;

	return 0;	
}
                    		