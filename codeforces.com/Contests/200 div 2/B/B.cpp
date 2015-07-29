/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, c;

	cin >> a >> b >> c;

	/*if (a + b == c) {
		cout << 0 << ' ' << b << ' ' << a;
		return 0;
	}

	if (a + c == b) {
		cout << a << ' ' << c << ' ' << 0;
		return 0;
	}

	if (b + c == a) {
		cout << b << ' ' << 0 << ' ' << c;
		return 0;
	}*/

	for (int i = 0; i <= min(a, b); i++) {
	 	int ta = a - i, tb = b - i;

	 	if (ta + tb == c) {
	 		cout << i << ' ' << tb << ' ' << ta;
	 		return 0;
	 	}
	}

	for (int i = 0; i <= min(b, c); i++) {
		int tb = b - i, tc = c - i;
		
		if (tb + tc == a) {
			cout << tb << ' ' << i << ' ' << tc;
			return 0;
		}
	}

	for (int i = 0; i <= min(a, c); i++) {
		int ta = a - i, tc = c - i;

		if (ta + tc == b) {
			cout << ta << ' ' << tc << ' ' << i;
			return 0;
		}
	}

	puts("Impossible");

	return 0;
}
