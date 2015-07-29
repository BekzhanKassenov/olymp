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

int try_(int a, int b) {
	if (a < 0 || b < 0 || a % 2 != b % 2)
		return INF;

	return max(a, b);	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m, i, j, a, b;

	cin >> n >> m >> i >> j >> a >> b;

	int res1x = -1, res1y = -1, res2x = -1, res2y = -1;

	if ((i - 1) % a == 0)
		res1x = (i - 1) / a;

	if ((n - i) % a == 0)
		res2x = (n - i) / a;

	if ((j - 1) % b == 0)
		res1y = (j - 1) / b;

	if ((m - j) % b == 0)
		res2y = (m - j) / b;

	int ans = min(min(try_(res1x, res1y), try_(res1x, res2y)), min(try_(res2x, res1y), try_(res2x, res2y)));

	if (ans < INF)
		cout << ans;
	else
		cout << "Poor Inna and pony!";

	return 0;
}
