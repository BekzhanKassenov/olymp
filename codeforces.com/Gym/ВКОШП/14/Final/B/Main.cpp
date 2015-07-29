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
#define File "che"

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

const int maxn = 300010;

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n, r;

	cin >> n >> r;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(all(a));

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		ans += (a.end() - upper_bound(all(a), a[i] + r));
	}

	cout << ans;

	return 0;
}

