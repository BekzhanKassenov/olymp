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

int n, k, x;
long long a[MAXN];

long long go(int k) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res |= a[i];
    }

    if (k == 0) {
        return res;
    }

    for (int i = 0; i < n; i++) {
        a[i] *= x;
        res = max(res, go(k - 1));
        a[i] /= x;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &x);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    printf("%I64d\n", go(k));

    return 0;
}
