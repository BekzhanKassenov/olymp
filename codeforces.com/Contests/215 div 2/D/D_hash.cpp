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

const ull MOD1 = 1000 * 1000 * 1000 + 7;
const ull MOD2 = 1000 * 1000 * 1000 + 9;
const ull base1 = 1000 * 1000 + 3;
const ull base2 = 1000 * 1000 + 33;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

const int maxn = 200010;
map <int, int> num;
ull p1[maxn], p2[maxn], h[maxn], bh, rev1, rev2;
bool calced[maxn];
int a[maxn], b[maxn], last;

ull bin_pow(ull a, int st, ull MOD) {
	ull res = 1;

	while (st) {
		if (st & 1) {
			res *= a;
			res %= MOD;
		}

		a *= a;
		a %= MOD;
		st >>= 1;
	}

	return res;
}

void init() {
	p1[0] = 1;
	p2[0] = 1;

	for (int i = 1; i < maxn; i++) {
		p1[i] = (p1[i - 1] * base1) % MOD1;
		p2[i] = (p2[i - 1] * base2) % MOD2;
	}

	rev1 = bin_pow(base1, MOD1 - 2, MOD1);
	rev2 = bin_pow(base2, MOD2 - 2, MOD2);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	init();

	int n, m, p;

	cin >> n >> m >> p;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!num.count(a[i]))
			num[a[i]] = ++last;

		a[i] = num[a[i]];
	}

	ull h1 = 0, h2 = 0;

	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (!num.count(b[i]))
			num[b[i]] = ++last;

		b[i] = num[b[i]];
		h1 = (h1 + b[i] * 1ull * p1[i]) % MOD1;
		h2 = (h2 + b[i] * 1ull * p2[i]) % MOD2;
	}

	bh = (h1 << 32) + h2;
	cout << bh << endl;

	for (int i = 0; i < n; i++) {
		int pos = i % p;

		if (i + (m - 1) * p < n) {
			if (!calced[pos]) {
				calced[pos] = true;
				h1 = 0, h2 = 0;

				int pos1 = i;

				for (int j = 0; j < m; j++) {
					h1 = (h1 + a[pos1] * 1ull * p1[i]) % MOD1;
					h2 = (h2 + a[pos1] * 1ull * p2[i]) % MOD2;
					pos1 += p;
				}

				h[pos] = (h1 << 32) + h2;

				cout << h[pos] << endl;
			} else {
				h1 = h[pos] >> 32;
				h2 = (h[pos] - (h1 << 32));

				h1 -= a[i - m * p];
				h2 -= a[i - m * p];

				h1 = (h2 * rev1) % MOD1;
				h2 = (h2 * rev2) % MOD2;

				h1 = (h1 + a[i] * p1[m - 1]) % MOD1;
				h2 = (h2 + b[i] * p2[m - 1]) % MOD2;

				h[pos] = (h1 << 32) + h2;	
			}
		} 

		if (h[pos] == bh) {
			cout << i << endl;
		}
	}

	return 0;
}
