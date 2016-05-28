#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 55;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

// dp[len][num][g]
long long dp[MAXN][MAXN][MAXN];

void precalc() {
    for (int i = 1; i < MAXN; i++) {
        dp[1][i][i] = 1;
    }

    for (int len = 1; len + 1 < MAXN; len++) {
        for (int num = 1; num < MAXN; num++) {
            for (int g = 1; g <= num; g++) {
                if (num % g != 0) {
                    continue;
                }

                for (int nxt = num + 1; nxt < MAXN; nxt++) {
                    dp[len + 1][nxt][gcd(g, nxt)] += dp[len][num][g];
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int K, S;
    scanf("%d%d", &K, &S);

    precalc();

    long long ans = 0;
    for (int g = 2; g <= S; g++) {
        int cnt = S / g;
        for (int i = 1; i <= cnt; i++) {
            ans += dp[K][i][1];
        }
    }

    if (ans > 10000) {
        puts("10000");
    } else {
        printf("%lld\n", ans);
    }


    return 0;
}
