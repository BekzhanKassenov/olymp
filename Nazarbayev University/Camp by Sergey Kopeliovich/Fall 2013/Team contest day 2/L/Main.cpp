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
#define File "milk"

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
	freopen(File".out", "w", stdout);

	ll n, b[2000], t[2000];
	ll sum, ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
		cin >> t[i];

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++)
			if (t[j] >= t[i])
				sum += (b[j] * t[i]);
		ans = max (ans, sum);
	}

	cout << ans;
	return 0;
}
