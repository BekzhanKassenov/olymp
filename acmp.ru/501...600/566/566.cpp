#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 110;

int dp[MAXN][MAXN][MAXN];
bool calced[MAXN][MAXN][MAXN];
int A, B, C, K;

int calc(int a, int b, int c) {
    int& ans = dp[a][b][c];

    if (calced[a][b][c])
        return ans;
        
    calced[a][b][c] = true;

    for (int k = 0; k <= c; k++) {
        for (int j = 0; j <= b; j++) {
            int rem = K - (3 * k + 2 * j);

            if (rem < 0) {
                ans = max(ans, calc(a, b - j, c - k) + 1);
                break;
            }

            if (rem > a)
                continue;

            ans = max(ans, calc(a - rem, b - j, c - k) + 1);
        }

        if (3 * k >= K)
            break;
    }

    return ans; 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &A, &B, &C, &K);

    printf("%d\n", calc(A, B, C));

    return 0;
}
