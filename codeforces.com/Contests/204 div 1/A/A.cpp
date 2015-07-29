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

	vector <double> a, b;

	double sum = 0, x;

	for (int i = 0; i < 2 * n; i++) {
		cin >> x;

		if (int(x) == x)
			a.push_back(x);
		else
			b.push_back(x);

		sum += x;	
	}

	if (a.size() % 2 != 0)
		b.push_back(a.back());

	sort(all(b));

	double res = 0;

	int len = b.size();

	for (int i = 0; i < (int)a.size(); i++)
		res += a[i];

	if (a.size() % 2 != 0)
		res -= a.back();

	double res1 = 0, res2 = 0;

	for (int i = 0; i < len / 2; i++) {
		res1 += floor(b[i]) + ceil(b[len / 2 + i]);
		res2 += ceil(b[i]) + floor(b[len / 2 + i]);
	}

	printf("%.3lf", min(abs(res + res1 - sum), abs(res + res2 - sum)));

	return 0;
}
