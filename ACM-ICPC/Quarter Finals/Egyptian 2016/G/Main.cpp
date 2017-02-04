/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "galactic"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int dp[MAXN][MAXN];
int fact[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    
    int T;
    cin >> T;

    dp[1][1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i][1] = 1;
        for (int mx = 2; mx <= i; mx++) {
            dp[i][mx] = dp[i - 1][mx - 1];
            dp[i][mx] += (1ll * dp[i - 1][mx] * mx) % MOD;
            dp[i][mx] %= MOD;
        }
    }

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
    }

    while (T--) {
        int n, k;
        cin >> n >> k;

        if (k > n) {
            cout << 0 << endl;
            continue;
        }


        long long ans = dp[n][k];
        ans = (1ll * ans * fact[k]) % MOD;

        cout << ans << endl;
    }

    return 0;
}
