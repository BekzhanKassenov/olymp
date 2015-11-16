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

int n;
int x[4], y[4];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    if (n == 1) {
        puts("-1");
        return 0;
    }

    if (n == 2 && (x[0] == x[1] || y[0] == y[1])) {
        puts("-1");
        return 0;
    }

    int xmin = INF, xmax = -INF;
    int ymin = INF, ymax = -INF;

    for (int i = 0; i < n; i++) {
        xmin = min(x[i], xmin);
        xmax = max(x[i], xmax);

        ymin = min(y[i], ymin);
        ymax = max(y[i], ymax);
    }

    printf("%d\n", (xmax - xmin) * (ymax - ymin));

    return 0;
}
