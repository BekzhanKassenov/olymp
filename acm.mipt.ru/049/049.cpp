#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1001;

int n, a[MAXN];

int dp[MAXN][MAXN];
bool goodDP[MAXN][MAXN];

int vec[MAXN];
bool goodVec[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    if (a[1] < 0) {
        puts("-1");
        return 0;
    }

    goodDP[1][1] = true;
    dp[1][1] = a[1];

    goodVec[1] = true;
    vec[1] = a[1];

    for (int i = 2; i <= n; i++) {
        for (int steps = 1; steps <= i; steps++) {
            if (goodDP[i - 1][steps - 1]) {
                goodDP[i][steps] = true;
                dp[i][steps] = dp[i - 1][steps - 1] + a[i];
            }

            if (goodVec[steps - 1] && (!goodDP[i][steps] || (dp[i][steps] < vec[steps - 1] + a[i]))) {
                goodDP[i][steps] = true;
                dp[i][steps] = vec[steps - 1] + a[i];
            }

            if (dp[i][steps] < 0) {
                goodDP[i][steps] = false;
            }
        }

        for (int steps = 1; steps <= i; steps++) {
            if (!goodVec[steps]) {
                continue;
            }
            
            vec[steps] -= 100;

            if (vec[steps] < 0) {
                goodVec[steps] = false;
            }
        }

        for (int steps = 1; steps <= i; steps++) {
            if (!goodDP[i][steps]) {
                continue;
            }

            if (!goodVec[steps] || vec[steps] < dp[i][steps]) {
                vec[steps] = dp[i][steps];
                goodVec[steps] = true;
            }
        }

    }
    
    int ans = -1;

    for (int steps = 1; steps <= n; steps++) {
        if (goodDP[n][steps]) {
            ans = steps;
            break;
        }
    }

    if (ans == -1) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
