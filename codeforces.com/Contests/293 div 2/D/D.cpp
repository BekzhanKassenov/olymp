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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, t;
double p;
double dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%lf%d", &n, &p, &t);

    dp[0][0] = 1;
    for (int tim = 1; tim <= t; tim++) {
        for (int num = 0; num <= n; num++) {
            dp[tim][num] = dp[tim - 1][num];

            if (num < n) {
                dp[tim][num] *= (1 - p);
            }

            if (num > 0) {
                dp[tim][num] += dp[tim - 1][num - 1] * p;
            }
        }
    }

    /*for (int tim = 1; tim <= t; tim++) {
        for (int num = 0; num <= n; num++) {
            printf("%.5lf ", dp[tim][num]);
        }

        puts("");
    }*/

    double ans = 0;
    for (int num = 0; num <= n; num++) {
        ans += dp[t][num] * num;
    }

    printf("%.14lf\n", ans);

    return 0;
}
