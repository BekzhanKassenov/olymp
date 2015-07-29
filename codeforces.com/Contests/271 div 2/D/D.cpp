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

int t, k, a, b;
int dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &t, &k);
    
    dp[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        if (i >= k) {
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }

        dp[i] = (dp[i] + dp[i - 1]) % MOD; 
    }

    for (int i = 2; i < MAXN; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    dp[0] = 0;

    while (t--) {
        scanf("%d%d", &a, &b);

        printf("%d\n", (dp[b] - dp[a - 1] + MOD) % MOD);
    }
    
    return 0;
}
