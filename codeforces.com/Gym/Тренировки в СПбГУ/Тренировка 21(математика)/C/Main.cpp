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

int gcd_ex(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}

	int x1, y1;

	int gg = gcd_ex(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;

	return gg;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int a, b;

	while (cin >> a >> b) {
		int x, y;
		int g = gcd_ex(a, b, x, y);

		cout << x << ' ' << y << ' ' << g << endl;
	}

	return 0;
}
