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
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

	int n;

	cin >> n;

	VI a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(all(a));

	ll res = 0;

	int cnt = a[0] / (n - 1);

	res = cnt * n;

	for (int i = 0; i < n; i++) {
		a[i] -= cnt * (n - 1);
	}

	int tmp = 0;

	if (a[0]) {
		for (int i = 1; i < n; i++) {
			if (i <= a[0])
				a[i] -= a[0] - 1;
			else
				a[i] -= a[0];
					
			tmp = max(tmp, a[i]);
		}
		res += a[0];
		res += tmp;
	} else 
		res += a[n - 1];

	cout << res;

	return 0;
}
