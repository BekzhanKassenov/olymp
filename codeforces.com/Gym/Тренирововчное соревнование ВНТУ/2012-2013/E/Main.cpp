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
	int n, d, x, y;

	scanf("%d%d%d%d", &n, &d, &x, &y);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int _x, _y;

		scanf("%d%d", &_x, &_y);

		if (sqr(x - _x) + sqr(y - _y) <= sqr(d))
			ans++;
	}

	cout << ans;

	return 0;
}
