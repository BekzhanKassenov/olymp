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

long long sum(ll n) {
	return ((n * (n + 1))) / 2;
}

int f(int n) {
	int ans = 0, cur = 1;

	while (n > 1) {
		ans += (cur * (n & 1));
		cur <<= 1;
		n >>= 1;
	}

	return ans;
}

ll brute(int n) {
 	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += f(i);
	}
	return ans;
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int n;
	cin >> n;
	long long ans = 0;

	for (int i = 0; ; i++) {
		if ((1 << i) < n) {
			ans += sum((1 << i) - 1);
			n -= (1 << i);
		} else {
			ans += sum(n - 1);
			break;
		}
	}

	cout << ans;

	return 0;
}
