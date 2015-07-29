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

	int n, d, m;

	cin >> n >> d;

	VI a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;

	int ans = 0;

	for (int i = 0; i < m; i++) {
		int res = -1;

		for (int j = 0; j < n; j++) {
		 	if (a[j] == INF)
		 		continue;

		 	if (res == -1 || (a[j] < a[res]))
		 		res = j;
		}

		if (res != -1) {
			ans += a[res];
			a[res] = INF;
		} else
			ans -= d;	
	}

	cout << ans;

	return 0;
}
