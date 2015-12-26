#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100010;
const int INF = (int)2e9;
int a[maxn];
int n, m, u, v, ans;

int main() {
	freopen("sparse.in", "r", stdin);
	freopen("sparse.out", "w", stdout);

	cin >> n >> m >> a[0] >> u >> v;
	u--, v--;

	for (int i = 1; i < n; i++) {
		a[i] = (23 * a[i - 1] + 21563) % 16714589;
	}

	for (int i = 1; i <= m; i++) {
		ans = INF;

		for (int j = min(u, v); j <= max(u, v); j++)
			ans = min(ans, a[j]);

		//cerr << u + 1 << ' ' << v + 1 << ' ' << ans << endl;	

		if (i != m) {
			u = (17 * (u + 1) + 751 + ans + 2 * i) % n;
			v = (13 * (v + 1) + 593 + ans + 5 * i) % n;
		}
	}

	cout << u + 1 << ' ' << v + 1 << ' ' << ans;

	return 0;
}
