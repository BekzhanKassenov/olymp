/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define left leftasd
#define right rightasd
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
const int maxn = 200010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int a[maxn], cnt[maxn], t[4 * maxn], flag[4 * maxn], n;

void push(int v, int l, int r) {
	if (l > r)
		return;

	if (flag[v] != 0) {
		t[v] += flag[v];
		
		if (l < r)
			flag[v << 1] = flag[(v << 1) + 1] = flag[v];

		flag[v] = 0;
	}
}

void update(int v, int l, int r, int z_l, int z_r, int val) {
	push(v, l, r);

	if (l > r || z_l > r || z_r < l)
		return;

	if (l >= z_l && r <= z_r) {
		flag[v] += val;
		push(v);
	} else {
	 	int mid = (l + r) >> 1;
	 	update(v << 1, l, mid, z_l, z_r, val);
	 	update((v << 1) + 1, mid + 1, r, z_l, z_r, val);
	 	t[v] = max(t[v << 1], t[(v << 1) + 1]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		if (a[i] == 1) {
			update(1, 0, n - 1, i + 1, n - 1, 1);
		} else {
			update(1, 0, n - 1, 0, i - 1);
		}
	}

	for (int i

	return 0;
}

