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

const int maxn = 1e6;

int l[maxn], r[maxn], x[maxn], a[maxn], flag[4 * maxn];

void push(int v, int l, int r) {
 	if (l < r && flag[v] != -1) {
 		if (l == r)
 			a[l] = flag[v];
 		else 
 			flag[v << 1] = flag[(v << 1) + 1] = flag[v];

 		flag[v] = -1;
 	}	
}

void upd(int v, int l, int r, int z_l, int z_r, int val) {
	push(v, l, r);
	if (l > r || z_l > z_r || l > z_r || r < z_l)
		return;

	if (l >= z_l && r <= z_r) {
		flag[v] = val;
		push(v, l, r);
	} else {
	 	int mid = (l + r) >> 1;

	 	upd(v << 1, l, mid, z_l, z_r, val);
	 	upd((v << 1) + 1, mid + 1, r, z_l, z_r, val);
	}	
}

int get(int v, int l, int r, int ind) {
	push(v, l, r);

	if (l > r || ind > r || ind < l)
		return 0;

	if (l == r && l == ind)
		return a[l];

	int mid = (l + r) >> 1;

	return get(v << 1, l, mid, ind) + get((v << 1) + 1, mid + 1, r, ind);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
	 	cin >> l[i] >> r[i] >> x[i];
	 	l[i]--, r[i]--, x[i]--;
	}

	a[x[n - 1]] = -1;

	for (int i = n - 1; i >= 0; i--) {
		upd(1, 0, n - 1, l[i], x[i] - 1, x[i] + 1);
		upd(1, 0, n - 1, x[i] + 1, r[i], x[i] + 1);
	}

	for (int i = 0; i < n; i++) {
	    int k = get(1, 0, n - 1, i);
	    cout << (k == -1 ? 0 : k) << ' ';
	}

	return 0;
}
