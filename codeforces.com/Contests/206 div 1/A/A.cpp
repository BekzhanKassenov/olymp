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

	ll n, l, r, ql, qr;

	cin >> n >> l >> r >> ql >> qr;

	vector <ll> a(n);

	ll sumr = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sumr += a[i];
	}

	ll suml = 0;
	ll cntr = n, cntl = 0;

	ll ans = min(sumr * l + ql * (n - 1), sumr * r + qr * (n - 1));

	for (int i = 0; i < n; i++) {
		suml += a[i];
		sumr -= a[i];
		cntl++;
		cntr--;

		ll pen = 0;

		if (cntl > cntr)
			pen = (cntl - cntr - 1) * ql;
		if (cntl < cntr)	
			pen = (cntr - cntl - 1) * qr;	

		ans = min(ans, suml * l + sumr * r + pen);
	}

	cout << ans;

	return 0;
}
