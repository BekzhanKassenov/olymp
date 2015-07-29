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
    
	int n;

	cin >> n;

	if (n == 0) {
		cout << 0 << ' ' << 0;
		return 0;
	}

	int ans = __builtin_popcount(n);

	string res;

	while (n) {
		res += (n & 1) + '0';
		n >>= 1;
	}

	reverse(all(res));

	cout << res << ans;
	return 0;
}
