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
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

int b[maxn], p[maxn], nmb[maxn], cnt[maxn], n, m, a, sz;
vector <int> c[maxn];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m >> a;

	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < m; i++)
		cin >> p[i];

	sort(p, p + m);

	for (int i = 0; i < m; i++) {
		if (sz == 0 || nmb[sz - 1] != p[i]) {
			nmb[sz] = p[i];
			cnt[sz++] = 1;
		} else
			cnt[sz - 1]++;
	}	

	for (int i = 0; i < n; i++) {
		int pos = upper_bound(nmb, nmb + sz, b[i]);

	}

	return 0;
}
