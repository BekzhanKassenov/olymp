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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int n, m;

	cin >> n >> m;

	VI a(n), b(m);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
		cin >> b[i];

	VI c;

	for (int i = 0; i < n; i++) {
		if (find(all(b), a[i]) != b.end()) {
			b.erase(find(all(b), a[i]));
		} else
			c.push_back(a[i]);
	}	

	int ans = 0;

	for (size_t i = 0; i < c.size(); i++) {
		if (upper_bound(all(b), c[i]) != b.end()) {
			b.erase(upper_bound(all(b), c[i]));
		} else
			ans++;
	}

	cout << ans;
	return 0;
}
