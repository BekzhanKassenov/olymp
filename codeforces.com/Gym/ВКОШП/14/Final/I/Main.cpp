/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "sochi"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const int maxn = 100010;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, d;
int a[maxn];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	cin >> n >> d;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	reverse(a, a + n);

	int lhs = a[0] - d, rhs = a[1] - d;
    ll len = (a[0] + a[1] - 2 * d);

    if (len < a[0]) {
    	cout << a[0];
    	return 0;
    }

    if (len <= 0) {
    	cout << 0;
    	return 0;
    }

	for (int i = 2; i < n; i++) {
		if (a[i] < d)
			break;

		ll templen = len + a[i] - 2 * d;

		if (templen < len)
			break;

		if (lhs >= 2 * d) {
			lhs = a[i] - d;
			len = templen;
		} else if (rhs >= 2 * d) {
			rhs = a[i] - d;
			len = templen;
		}
	}

	cout << len;

	return 0;
}

