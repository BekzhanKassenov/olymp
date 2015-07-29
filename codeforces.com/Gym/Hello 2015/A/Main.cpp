/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long mask_t;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 20010;
const int MAXA = 65;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN];
int cnt[MAXN][MAXA];

mask_t get_mask(int l, int r) {
 	mask_t result = 0;

 	for (int i = 0; i < MAXA; i++) {
 	 	if (cnt[r][i] - cnt[l - 1][i] > 0)
 	 		result |= (1ull << i);
 	}

 	return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i++) {
	 	for (int j = 0; j < MAXA; j++)
	 		cnt[i][j] = cnt[i - 1][j];

	 	cnt[i][a[i]]++;
	}

	for (int i = 1; i <= n; i++) {
	 	for (int j = i; j <= n; j = get_next(i, j)) {

	 	}
	}

	return 0;
}
