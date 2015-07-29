#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int dp[35][1 << 3], n;

bool check(int mask1, int mask2) {
    for (int i = 0; i < 3; i++) {
        if (mask2 & (1 << i)) {
            if ((mask1 & (1 << i)))
                return false;

            mask1 |= 1 << i;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (!(mask1 & (1 << i))) {
            if (i < 2 && !(mask1 & (1 << (i + 1)))) {
                mask1 |= 1 << i;
                mask1 |= 1 << (i + 1);
            } else
                return false;
        }
    }

    return true;
}

int main() {                           
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);

    dp[1][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int cur = 0; cur < (1 << 3); cur++) {
            for (int nxt = 0; nxt < (1 << 3); nxt++) {
                if (check(cur, nxt))
                    dp[i + 1][nxt] += dp[i][cur];
            } 
        }
    }

    printf("%d\n", dp[n + 1][0]);

    return 0;
}
