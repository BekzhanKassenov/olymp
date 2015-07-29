/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()
#define File "courier"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

stringstream result;

const int maxn = 10010;
int g[maxn][4], n, x, y;

void dfs(int v) {
	for (int i = 0; i < 4; i++) {
		if (g[v][i] != -1) {
			int to = g[v][i];
			
			g[v][i] = -1;
			g[to >> 2][to & 3] = -1;

			result << (v << 2) + i + 1 << ' ' << to + 1 << ' ';
			
			dfs(to >> 2);
		}
	}
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < 2 * n; i++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x >> 2][x & 3] = y;
		g[y >> 2][y & 3] = x;
	}

	dfs(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			if (g[i][j] != -1) {
				puts("NO");
				return 0;
			}
	}

	puts("YES");

	cout << result.str();

	return 0;
}
