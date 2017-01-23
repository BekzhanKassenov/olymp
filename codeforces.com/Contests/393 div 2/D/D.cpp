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

int n;
int t[MAXN];
int dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    auto updateDp = [&](int i, int len, int cost) {
        for (int j = i - 1; j >= 0 && t[i] <= t[j] + len - 1; j--) {
            int val = cost;
            if (j > 0) {
                val += dp[j - 1];
            }

            dp[i] = min(dp[i], val);
        }
    };

    dp[0] = 20;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + 20;

        updateDp(i, 90, 50);
        updateDp(i, 1440, 120);
    }

    printf("%d\n", dp[0]);
    for (int i = 1; i < n; i++) {
        printf("%d\n", dp[i] - dp[i - 1]);
    }

    return 0;
}
