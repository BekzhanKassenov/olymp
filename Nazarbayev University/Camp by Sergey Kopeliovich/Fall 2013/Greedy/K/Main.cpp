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
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd
#define File "boxes"

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

const int maxn = 100010;

PII a[maxn];

bool cmp(const PII& a, const PII& b) {
	if (a.F + a.S < b.F + b.S)
		return true;

	if (a.F + a.S > b.F + b.S)
		return false;

	if (a.F < b.F)
		return true;

	if (a.F > b.F)
		return false;

	if (a.S < b.S)
		return true;

	return false;
}

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	sort(a, a + n, cmp);

	ll sum = 0;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (a[i].S >= sum) {
			sum += a[i].F;
			ans++;
		}
	}

	cout << ans;

	return 0;
}
