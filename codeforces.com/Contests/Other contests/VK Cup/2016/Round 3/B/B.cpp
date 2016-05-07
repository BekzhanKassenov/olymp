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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int a, b, c, d;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (n == 4) {
        puts("-1");
        return 0;
    }

    if (k <= n) {
        puts("-1");
        return 0;
    }

    vector <int> rest;
    rest.reserve(n);

    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) {
            rest.push_back(i);
        }
    }

    printf("%d %d", a, c);
    for (int v: rest) {
        printf(" %d", v);
    }

    printf(" %d %d\n", d, b);

    printf("%d %d", c, a);
    for (int v: rest) {
        printf(" %d", v);
    }

    printf(" %d %d\n", b, d);

    return 0;
}
