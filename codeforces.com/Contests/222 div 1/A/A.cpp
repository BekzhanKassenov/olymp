/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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

const int maxn = 550;

int n, m, k, g[maxn][maxn], tin[maxn][maxn], fup[maxn][maxn], timer;
bool is_cuting_point[maxn][maxn], used[maxn][maxn];
char c;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, int px = -1, int py = -1) {
	used[x][y] = true;

	tin[x][y] = fup[x][y] = ++timer;

	int cnt_ch = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx == px && ny == py)
			continue;

		if (ok(nx, ny) && !g[nx][ny]) {
			if (used[nx][ny])
				fup[x][y] = min(fup[x][y], tin[nx][ny]);
			else {
			 	dfs(nx, ny, x, y);

			 	fup[x][y] = min(fup[x][y], fup[nx][ny]);

			 	if (fup[nx][ny] >= tin[x][y] && px != -1) {
			 		is_cutting_point[x][y] = true;
			 	}

			 	cnt_ch++;
			}	
		}
	}

	if (px == -1 && cnt_ch > 1)
		is_cutting_point[x][y] = true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;

			if (c == '#')
				g[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (!used[i][j])
				dfs(i, j);
	}

	for (int i = 0; i < n && k; i++) {
		for (int j = 0; j < m && k; j++) {
			if (!is_cutting_point(i, j))
				g[i][j] = 2;
		}
	}

	return 0;
}
