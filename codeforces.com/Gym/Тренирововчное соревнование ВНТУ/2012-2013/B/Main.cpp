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
const int maxn = 1000010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

vector <int> g[maxn];
bool used[maxn];
int n, m, x, y;

void dfs(int v) {
	used[v] = true;

	for (size_t i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	
	int k;

	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(k);

	for (int i = 1; i <= n; i++)
		if (used[i]) {
			printf("%d\n", i);
			break;
		}

	return 0;
}
