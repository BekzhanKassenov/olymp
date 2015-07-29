/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
                                             
char table[100][100];
int dist[100][100][4];
int n, m;

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int turn(int dir, int type) {
	if (type == 3)
		return dir;
	if (type == 1) 
		return (dir + 2) % 4;

	if (type == 2) {
		if (dir == 0)
			return 1;

		if (dir == 1)
			return 0;

		if (dir == 2)
			return 3;

	   	if (dir == 3)
	   		return 2;
	}
	return 0;
}

int bfs(int x, int y, int dir) {
	queue <PII> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = INF;
	}
	q.push(MP(x * m + y, dir));
	dist[x][y][dir] = 0;
	
	int ans = INF;

	while (!q.empty()) {
		PII a = q.front();
		int curx = a.F / m;
		int cury = a.F % m;
		int curdir = a.S;
		q.pop();

		if (table[curx][cury] == '/' || table[curx][cury] == '`') { 
			int tdir = turn(curdir, (table[curx][cury] == '/') ? 1 : 2);
			int tx = curx + dx[tdir];
			int ty = cury + dy[tdir];

			if (!ok(tx, ty) && (curx != x || cury != y))
				ans = min(ans, dist[curx][cury][curdir]);

			if (ok (tx, ty) && table[tx][ty] != '#' && dist[tx][ty][tdir] > dist[curx][cury][curdir]) {
				dist[tx][ty][tdir] = dist[curx][cury][curdir];
				q.push(MP(tx * m + ty, tdir));
			}
		} 
		if (table[curx][cury] == '.') {
			for (int i = 1; i <= 3; i++) {
				int tdir = turn(curdir, i);
				int tx = curx + dx[tdir];
				int ty = cury + dy[tdir];

				if (!ok(tx, ty) && (curx != x || cury != y))
					ans = min(ans, dist[curx][cury][curdir] + (tdir != curdir));

				if (ok(tx, ty) && table[tx][ty] != '#' && dist[tx][ty][tdir] > dist[curx][cury][curdir] + (tdir != curdir)) {
					dist[tx][ty][tdir] = dist[curx][cury][curdir] + (tdir != curdir);
					q.push(MP(tx * m + ty, tdir));
				}
			}
		}
	}
	return ans;
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		cin >> table[i];      

	int xs = -1, ys = -1, stdir = -1;

	for (int i = 0; i < n; i++) {
		if (table[i][0] == '.') {
			if (xs == -1) {
				xs = i;
				ys = 0;
				stdir = 1;
			}	
		}
		if (table[i][m - 1] == '.') {
			if (xs == -1) {
				xs = i;
				ys = m - 1;
				stdir = 2;
			}
		}

	}

	for (int j = 0; j < m; j++) {
		if (table[0][j] == '.') {
			if (xs == -1) {
				xs = 0;
				ys = j;
				stdir = 0;
			}
		}
		if (table[n - 1][j] == '.') {
			if (xs == -1) {
				xs = n - 1;
				ys = j;
				stdir = 3;
			}
		}
	}

	int ans = bfs(xs, ys, stdir);

	if (ans == INF)
		cout << -1;
	else
		cout << ans;	

	return 0;
}
