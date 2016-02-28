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
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long t1[MAXN], t2[MAXN];
int n, k;
long long a, b;
int q;

void update(long long t[MAXN], int pos, long long delta) {
	for (int i = pos; i <= n; i |= i + 1) {
		t[i] += delta;
	}
}

long long sum(long long t[MAXN], int pos) {
	long long res = 0;
	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}

	return res;
}

long long sum(long long t[MAXN], int l, int r) {
	return sum(t, r) - sum(t, l - 1);
}

void add(long long t[MAXN], int pos, int cnt, long long lim) {
	long long oval = sum(t, pos, pos);
	long long nval = min(lim, oval + cnt);

	update(t, pos, nval - oval);
}

long long query(int p) {
	return sum(t1, 1, p - 1) + sum(t2, p + k, n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    scanf("%lld%lld", &a, &b);

    scanf("%d", &q);

    while (q--) {
    	int type;
    	scanf("%d", &type);

    	if (type == 1) {
    		int d;
    		long long val;

    		scanf("%d%lld", &d, &val);

    		add(t1, d, val, b);
    		add(t2, d, val, a);
    	} else {
    		int d;
    		scanf("%d", &d);

    		printf("%lld\n", query(d));
    	}
    }

    return 0;
}
