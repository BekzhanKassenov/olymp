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

const int maxn = 110;
int g[110][110], n, m, x, y, c;
                           
int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c;

		g[--x][--y] = c;
	}

	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (g[j][k] && g[k][i]) {// && g[i][j]) {
					//cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
					int mn = min(g[j][k], g[k][i]);
					g[j][k] -= mn;
					g[k][i] -= mn;
					g[j][i] += mn;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += g[i][j];

	cout << ans;

	return 0;
}
