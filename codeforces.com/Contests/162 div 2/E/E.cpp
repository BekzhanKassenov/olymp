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
const long long INF = (long long)1e15;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q, imax1, imax2;
int c[MAXN];
long long dp[MAXN];
long long v[MAXN];
long long a, b, ans;

void update(int idx, long long val) {
    if (val > dp[imax1]) {
        if (imax1 == idx)
            imax1 = idx;
        else {
            imax2 = imax1;
            imax1 = idx;
        }
        return;
    }
    
    if (val > dp[imax2]) {
        if (idx == imax1)
            return;

        imax2 = idx;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%I64d", &v[i]);

    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);

    while (q--) {
        for (int i = 0; i <= n; i++)
            dp[i] = -INF;

        imax1 = 0, imax2 = 0;
        ans = 0;

        scanf("%I64d%I64d", &a, &b);

        for (int i = 1; i <= n; i++) {
            if (dp[c[i]] != -INF)
                dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
            
            dp[c[i]] = max(dp[c[i]], b * v[i]);
            
            long long vmax = dp[imax1];
            if (imax1 == c[i])
                vmax = dp[imax2];

            if (vmax != -INF)
                dp[c[i]] = max(dp[c[i]], vmax + b * v[i]);
            
            update(c[i], dp[c[i]]);
            ans = max(ans, dp[c[i]]);
        }

        printf("%I64d\n", ans);
    }
    
    return 0;
}