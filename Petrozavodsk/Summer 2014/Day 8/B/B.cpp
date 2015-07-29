#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 110;
const int MOD = 175781251;

#define ALL(x) (x).begin(), (x).end()

int dp[MAXN][MAXN], fact[MAXN], power[MAXN], power2[MAXN];
int ans[MAXN], n, C[MAXN][MAXN], dp1[MAXN][MAXN], rev2;

int binpow(int n, int st) {
    int res = 1;

    while (st) {
        if (st & 1) 
            res = (1ll * res * n) % MOD;

        n = (1ll * n * n) % MOD;
        st >>= 1;
    }

    return res;
}


int split(int n) {
    if (n == 1)
        return 1;

    int ans = 0;
    for (int l = 1; l < n; l++) {
        int r = n - l;

        ans = (ans + 1ll * C[n][l] * dp[l][r]) % MOD;
    }
    
    ans = (1ll * ans * rev2) % MOD;

    return ans;
}

void init() {
    C[0][0] = 1;
    rev2 = binpow(2, MOD - 2);

    for (int i = 1; i <= 100; i++) {
        C[i][0] = C[i][i] = 1;

        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }

    }

    fact[0] = 1;
    power[0] = 1;
    power2[0] = 1;

    for (int i = 1; i <= 100; i++) {
        power[i] = (1ll * power[i - 1] * 3) % MOD;
        power2[i] = (1ll * power2[i - 1] * 2) % MOD;
        dp[1][i] = power2[i];
        dp[i][1] = power2[i];
    }

    dp[2][2] = 5;

    for (int i = 3; i <= 100; i++) {
        dp[i][2] = (dp[i - 1][2] * 8ll) % MOD;
        dp[2][i] = (dp[2][i - 1] * 8ll) % MOD;
    }

    for (int l = 3; l <= 100; l++) {
        for (int r = 3; r <= 100; r++) {
            dp[l][r] = (1ll * dp[l - 1][r] * (power[r] - 1 + MOD)) % MOD;
            //dp[l][r] = (dp[l][r] + 1ll * dp[l][r - 1] * (power[l] - 1 + MOD)) % MOD;

            //assert(dp[l][r] == (1ll * dp[l][r - 1] * (power[l] - 1 + MOD)) % MOD);
        }
    }

    for (int i = 1; i <= 100; i++) {
        dp1[i][1] = split(i);
        ans[i] = dp1[i][1];

        for (int k = 2; k <= i; k++) {
            for (int cnt = 1; cnt < i; cnt++) {
                int temp = (1ll * C[i][cnt] * split(cnt)) % MOD;

                temp = (1ll * temp * dp1[i - cnt][k - 1]) % MOD;
                dp1[i][k] = (dp1[i][k] + temp) % MOD;
            }

            ans[i] = (ans[i] + dp1[i][k]) % MOD;
        }
    }

    for (int i = 1; i <= 10; i++) {
        cerr << split(i) << endl;
    }
}

int main() {
    assert(freopen("bipartite.in", "r", stdin));
    assert(freopen("bipartite.out", "w", stdout));

    init();

    while (scanf("%d", &n) == 1 && n != 0) {
        printf("%d\n", ans[n]);
    }

    return 0;
}