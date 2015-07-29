/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "dwarfs"

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
const int maxn = 200010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, x, y, xs, ys, ans[maxn], ansx[maxn], ansy[maxn];
vector <int> g[maxn], path;

bool dfs(int v, int pr = -1) {
	if (v == ys) {
		path.push_back(v);
		return true;
	}

	for (size_t i = 0; i < g[v].size(); i++) {
		if (g[v][i] != pr && dfs(g[v][i], v)) {
			path.push_back(v);
			return true;
		}
	}

	return false;
}

bool can_go(int v, int to, int pos) {
	if (path[pos] == v) {
		if (pos > 0 && path[pos - 1] == to) 
			return false;             
			
		if (pos < (int)path.size() - 1 && path[pos + 1] == to)
			return false;

		return true;	
	}

	return true;
}

int dfs1(int v, int pos, int pr = -1) {
	for (size_t i = 0; i < g[v].size(); i++) {
	 	if (can_go(v, g[v][i], pos) && g[v][i] != pr) {
	 		ans[v] = max(ans[v], dfs1(g[v][i], pos, v));
		}
	}

	ans[v]++;

	return ans[v];
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &x, &y);

		g[--x].push_back(--y);
		g[y].push_back(x);
	}

	scanf("%d%d", &xs, &ys);
	xs--, ys--;

	dfs(xs);

	for (size_t i = 0; i < path.size(); i++)
		dfs1(path[i], i);
	
	ansx[0] = ans[path[0]];

	for (size_t i = 1; i < path.size(); i++) {
		ansx[i] = max(ansx[i - 1], ans[path[i]] + (int)i);
	}

	ansy[path.size() - 1] = ans[path.back()];

	for (int i = path.size() - 2; i >= 0; i--) {
		ansy[i] = max(ansy[i + 1], ans[path[i]] + (int)path.size() - i - 1);
	}

	int res = 0;

	for (size_t i = 0; i < path.size() - 1; i++) {
		res = max(res, min(ansx[i], ansy[i + 1]));
	}

	printf("%d\n", res);

	return 0;
}
