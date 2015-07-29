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
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal
#define File "a"

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
	freopen(File".in", "r", stdin);

	int n;

	cin >> n;

	vector <pair <PII, int> > a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].F.F >> a[i].F.S >> a[i].S;

	sort(all(a));
	reverse(all(a));

	vector <ll> dp(n, INF);

	dp[0] = a[0].F.S * a[0].S;

	for (int i = 1; i < n; i++) {
	 	for (int j = 0; j < i; j++) {
	 		if (a[i].F.F < a[j].F.S) 
	 			dp[i] = min(dp[i], (a[j].F.S - a[i].F.F) * a[j].S + dp[j]);
	 	}
	}
	cout << dp[n - 1];

	return 0;
}
