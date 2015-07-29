/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "fib"

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

ull fib[100];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	ll n;
	cin >> n;

	fib[0] = 1;
	fib[1] = 1;

	int sz = 0;

	for (int i = 2; ; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		sz = i;
		if (fib[i] > n)
			break;
	}
	sz--;
	ll ans = 0;

	while (sz > 0) {
		ll cnt = (n - fib[sz]) / n;

		if (n - (cnt + 1) / sz > 0)
			cnt++;
		cout << sz << ' ' << fib[sz] << ' ' << n << ' ' << cnt << endl;
		n -= cnt * sz;
		cout << n << endl;
		ans += cnt;
		while (sz >= 1 && fib[sz] > n)
			sz--;
	}

	cout << ans;

	return 0;
}
