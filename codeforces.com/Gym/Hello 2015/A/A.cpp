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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q;
long long a[MAXN];
long long start[MAXN];
long long T;
long long total;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        total += a[i];
    }

    start[0] = 0;
    for (int i = 1; i < n; i++) {
        start[i] = start[i - 1] + a[i - 1];
    }

    while (q--) {
        scanf("%lld", &T);

        T %= total;
        int pos = upper_bound(start, start + n, T) - start;

        printf("%d\n", pos);
    }

    return 0;
}
