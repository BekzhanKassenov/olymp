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

int g[310][310], n, k, m, dfs_ans;
bool used[310];

void dfs(int v) {
	used[v] = true;

	dfs_ans++;

	for (int i = 0; i < n; i++)
		if (g[v][i] && !used[i])
			dfs(i);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m >> k;

	if (k == n) {
		cout << -1;
		return 0;
	}

	vector <int> a(k);

	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i != j)
				g[i][j] = 1;
	}

	for (int i = 1; i < k; i++) {
		g[a[0]][a[i]] = g[a[i]][a[0]] = 0;
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cnt += g[i][j];

	cnt >>= 1;


	if (cnt < m) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n && cnt > m; i++) {
		for (int j = 0; j < i && cnt > m; j++) {
			if (g[i][j] != 1)
				continue;

			g[i][j] = g[j][i] = 0;

			dfs_ans = 0;
			memset(used, false, sizeof used);
			dfs(0);

			if (dfs_ans < n) 
				g[i][j] = g[j][i] = 1;
			else
				cnt--;
		}
	}

	if (cnt != m) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (g[i][j])
				cout << j + 1 << ' ' << i + 1 << endl;
	}

	return 0;
}
