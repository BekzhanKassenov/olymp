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

int n, x, minn = INF, maxx;
ll cntmin, cntmax;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x < minn) {
            minn = x;
            cntmin = 1;
        } else if (x == minn)
            cntmin++;

        if (x > maxx) {
            maxx = x;
            cntmax = 1;
        } else if (x == maxx)
            cntmax++;
    }

    printf("%d ", maxx - minn);

    if (minn == maxx)
        printf("%I64d\n", cntmax * (cntmax - 1) / 2);
    else
        printf("%I64d\n", cntmax * cntmin);

    return 0;
}
