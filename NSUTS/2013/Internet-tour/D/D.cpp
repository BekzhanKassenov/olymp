/****************************************
**        Solution by NU 02:           **
**		  Bekzhan Kassenov             **
**		  Anuar Serikov                **
**		  Nursultan Zarlyk             **
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

template <typename T>
inline T cub(T n) {
	return (n * n * n);
}

double f(double x, double r) {
	return (r * x / 3.0 - x / r * sqr(x) / 3.0 + sqr(x) / (4.0 * sqr(r)) * sqr(x));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double r, h;

	cin >> r >> h;

	double res = 0;
	if (h / 2.0 >= r) {
		res = (cub(r) / (2.0) + h / 3.0 * r - 2.0 / 3.0 * sqr(r)) / h;
		printf("%.10lf", res);
	} else {
		double x = r - h / 2.0;

		res = f(r, r) - f(x, r);
		
		printf("%.10lf", res);

		assert(res >= 0);
	}

	return 0;
}
