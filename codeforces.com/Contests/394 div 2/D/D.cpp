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

int n, l, r;
int a[MAXN], p[MAXN];
int b[MAXN], c[MAXN];
int pos[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &l, &r);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }

    b[pos[1]] = l;
    c[pos[1]] = b[pos[1]] - a[pos[1]];
    for (int i = 2; i <= n; i++) {
        int p = pos[i];
        b[p] = a[p] + c[pos[i - 1]] + 1;
        if (b[p] < l) {
            b[p] = l;
        }
        if (b[p] > r) {
            b[p] = r;
        }

        c[p] = b[p] - a[p];
        if (c[p] <= c[pos[i - 1]]) {
            puts("-1");
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}
