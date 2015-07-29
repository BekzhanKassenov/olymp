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
#define File "termotaur"

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
int p[501][501], d[501][501], n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(int x, int y) {
	if (p[x][y] != -1)
		return;

	int dir = -1;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (ok(tx, ty) && d[tx][ty] < d[x][y] && (dir == -1 || d[x + dx[dir]][y + dy[dir]] > d[tx][ty]))
			dir = i;
	}

	if (dir == -1)
		p[x][y] = d[x][y];
	else {
		dfs(x + dx[dir], y + dy[dir]);
		p[x][y] = p[x + dx[dir]][y + dy[dir]];
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
			p[i][j] = -1;
		}

	int m, x, y;

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--, y--;
		dfs(x, y);
		cout << p[x][y] << endl;
	}
	return 0;
}
