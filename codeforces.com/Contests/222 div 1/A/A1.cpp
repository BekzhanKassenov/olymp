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

bool used[maxn][maxn];
int n, m, k, g[maxn][maxn], gl[maxn][maxn];
set <pair <PII, PII> > st;
char c;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, int px = -1, int py = -1, int gg = 0) {
	used[x][y] = true;
	gl[x][y] = gg;

	if (px != -1) {
		st.insert(MP(MP(x, y), MP(px, py)));
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (ok(tx, ty) && !used[tx][ty] && !g[tx][ty]) {
			dfs(tx, ty, x, y, gg + 1);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;

			g[i][j] = (c == '#');
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!used[i][j] && !g[i][j]) {
				dfs(i, j);
				//cout << i << ' ' << j << endl;
			}
			//cout << endl;

	vector <pair <int, PII> > vec;

	vec.reserve(n * m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!g[i][j]) {
			 	vec.push_back(MP(gl[i][j], MP(i, j)));
			 	//cout << i << ' ' << j << ' '<< gl[i][j] << endl;
			}
		}
	}

	sort(all(vec));
	reverse(all(vec));


	for (int i = 0; i < k; i++) {
		g[vec[i].S.F][vec[i].S.S] = 2;
	}

	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
	     	if (g[i][j] == 0)
	     		cout << '.';
	     	else if (g[i][j] == 1)
	     		cout << '#';
	     	else
	     		cout << 'X';
	    }
	    cout << endl;
	}
	return 0;
}
