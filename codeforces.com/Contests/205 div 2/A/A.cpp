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

	VI x(n), y(n);

	int s1 = 0, s2 = 0;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i] %= 2;
		y[i] %= 2;
		s1 ^= x[i];
		s2 ^= y[i];
	}

	if (!s1 && !s2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int t_s = s1 ^ x[i] ^ y[i];
		int t_t = s2 ^ y[i] ^ x[i];

		if (!t_s && !t_t) {
			cout << 1;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
