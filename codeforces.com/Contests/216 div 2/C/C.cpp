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

const int maxn = 100010;
int x, y, t, res;
vector <pair <int, bool> > g[maxn];
stringstream ss;

bool dfs(int v, int pr) {
	bool ans = false;
	bool bad = false;

	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i].F;

		if (pr == to) {
			if (g[v][i].S)
				bad = true;

			continue;
		}

		if (g[v][i].S)
			ans = true;

		ans |= dfs(to, v);	
	}

	if (bad) {
		if (!ans) {
			ss << v + 1 << ' ';
			res++;
		}
	}

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> t;

		g[--x].push_back(MP(--y, t == 2));
		g[y].push_back(MP(x, t == 2));
	}

	dfs(0, -1);

	cout << res << endl;

	cout << ss.str();

	return 0;
}
