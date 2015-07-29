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

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
double a[maxn], res;
double dp[maxn], dp1[maxn], bad[maxn], bad1[maxn];

int cmp(double aa, double bb) {
    if (fabs(aa - bb) < EPS)
        return 0;

    if (aa - bb > 0.0)
        return 1;

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = a[i];
        bad[i] = 1 - a[i];
        dp1[i] = a[i];
        bad1[i] = 1 - a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            double temp = dp[j] * (1.0 - a[i]) + a[i] * bad[j];

            if (cmp(temp, dp[i]) == 1 || (cmp(temp, dp[i]) == 0 && cmp(bad[i], bad[j] * (1 - a[i])) == -1)) {
                dp[i] = temp;
                bad[i] = bad[j] * (1 - a[i]);
            }

            temp = dp1[j] * (1 - a[i]) + a[i] * bad1[j];

            if (cmp(temp, dp[i]) == 1 || (cmp(temp, dp[i]) == 0 && cmp(bad[i], bad[j] * (1 - a[i]) == -1))) {
                dp[i] = temp;
                bad[i] = bad1[j] * (1 - a[i]);
            }

            temp = bad1[j] * (1 - a[i]);

            if (cmp(temp, bad1[i]) == 1 || (cmp(temp, bad1[i]) == 0 && cmp(dp1[i], dp1[j] * (1 - a[i]) + bad1[j] * a[i]) == -1)) {
                dp1[i] = dp1[j] * (1 - a[i]) + bad1[j] * a[i];
                bad1[i] = temp;
            }
        }


        if (cmp(dp[i], res) == 1)
            res = dp[i];
    }

    cout << fixed << setprecision(15) << res;

    return 0;
}
