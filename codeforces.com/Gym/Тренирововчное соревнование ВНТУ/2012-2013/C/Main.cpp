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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

vector <int> t[4 * maxn];
int a[maxn], nxt[maxn], n, m, l, r;
map <int, int> prv;

void build(int v, int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		t[v].push_back(nxt[l]);
		return;
	}

	int mid = (l + r) >> 1;

	build(v << 1, l, mid);
	build((v << 1) + 1, mid + 1, r);

	merge(all(t[v << 1]), all(t[(v << 1) + 1]), back_inserter(t[v]));
}

int get_ans(int v, int l, int r, int q_l, int q_r) {
	if (l > r || l > q_r || r < q_l) {
		return 0;
	}

	if (l >= q_l && r <= q_r) {
		return (t[v].end() - upper_bound(all(t[v]), q_r));
	}

	int mid = (l + r) >> 1;

	return (get_ans(v << 1, l, mid, q_l, q_r) + get_ans((v << 1) + 1, mid + 1, r, q_l, q_r));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		nxt[i] = INF;

		if (prv.count(a[i])) {
			nxt[prv[a[i]]] = i;
		}

		prv[a[i]] = i;
	}

	build(1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &l, &r);

		l--, r--;

		printf("%d\n", get_ans(1, 0, n - 1, l, r));
	}

	return 0;
}
