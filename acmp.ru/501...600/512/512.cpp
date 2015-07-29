#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, k, ans;
char can[15][15];
int dp[11][1 << 10];

int go(int pos, int maskg, int cnt) {
    int& ans = dp[pos][maskg];
    if (ans != -1) {
        return ans;
    }

    if (cnt == k) {
        return 1;
    }

    if (pos == n) {
        return 0;
    }

    ans = 0;
    for (int i = 0; i < m; i++) {
        if (can[pos][i] == 'Y' && !(maskg & (1 << i))) {
            ans += go(pos + 1, maskg | (1 << i), cnt + 1);
        }
    }

    ans += go(pos + 1, maskg, cnt);
    return ans;     
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d %d\n", &n, &m, &k);

    for (int i = 0; i < n; i++)
        gets(can[i]);

    memset(dp, 255, sizeof dp);

    printf("%d\n", go(0, 0, 0));

    return 0;
}