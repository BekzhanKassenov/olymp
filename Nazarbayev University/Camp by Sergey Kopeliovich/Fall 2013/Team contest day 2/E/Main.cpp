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
#define File "square"

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

	int a[2000][2000], d[2000][2000], n, k;
int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	char c[2000][2000];
	ll ans = INF, sum;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == 'G')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	d[1][1] = a[1][1];

	for (int i = 2; i <= n; i++)
		d[i][1] = d[i - 1][1] + a[i][1],
		d[1][i] = d[1][i - 1] + a[1][i];

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
			d[i][j] = a[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];

	for (int i = k; i <= n; i++)
		for (int j = k; j <= n; j++) {
			sum = d[i][j] - d[i - k][j] - d[i][j - k] + d[i - k][j - k];
	        ans = min (ans, min (sum, k * k - sum));
	    }
	    cout << ans;
	return 0;
}
