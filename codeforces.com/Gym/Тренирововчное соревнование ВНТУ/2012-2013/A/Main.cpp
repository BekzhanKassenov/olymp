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
	int t;

	cin >> t;

	while (t--) {
		int n, m;

		cin >> n >> m;

		vector <vector <int> > a(n, vector <int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}

		double res = 1;

		int k;

		cin >> k;

		for (int i = 0; i < n; i++) {
			double ans = 0;

			for (int j = 0; j < m; j++)
				if (a[i][j] == k)
					ans += 1;

			res *= ans;
			res /= (m + .0);
		}

		printf("%.14lf\n", res);
	}

	return 0;
}
