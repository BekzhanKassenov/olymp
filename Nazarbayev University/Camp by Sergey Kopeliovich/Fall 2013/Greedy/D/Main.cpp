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
#define File "product"

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

const int maxn = 1010;
int x[maxn], y[maxn];

int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	
	int t;
	cin >> t;

	for (int j = 1; j <= t; j++) {
		int n;

	 	cin >> n;
	 	for (int i = 0; i < n; i++)
	 		cin >> x[i];

	 	sort(x, x + n);
	 	for (int i = 0; i < n; i++)
	 		cin >> y[i];

	 	sort(y, y + n);
	 	reverse(y, y + n);

		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += x[i] * 1ll * y[i];	
		cout << "Case #" << j << ": " << ans << endl;
	}
	
	return 0;
}
