#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 33;

int n, k, len;

int dp[MAXN][MAXN][2];
bool calced[MAXN][MAXN][2];
int d[MAXN];

int f(int pos, int cnt, bool smaller) {
    if (cnt > k) {
        return 0;
    }
    
    if (pos == len) {
        return cnt == k;
    }

    if (calced[pos][cnt][smaller]) {
        return dp[pos][cnt][smaller];
    }
    
    calced[pos][cnt][smaller] = true;

    int upper = 0;
    if (smaller) {
        upper = 1;
    } else {
        upper = d[pos];
    }

    for (int dig = 0; dig <= upper; dig++) {
        if (smaller) {
            dp[pos][cnt][smaller] += f(pos + 1, cnt + (dig == 0), true);
        } else {
            dp[pos][cnt][smaller] += f(pos + 1, cnt + (dig == 0), dig < d[pos]);
        }
    }

    return dp[pos][cnt][smaller];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    if (k >= 32) {
        puts("0");
        return 0;
    }

    for (int i = 0; n > 0; i++, len++) {
        d[i] = n & 1;
        n >>= 1;
    }

    reverse(d, d + len);

    int ans = f(1, 0, false);
    for (int i = 1; i + 1 <= len; i++) {
        ans += f(i + 1, 0, true);
    }

    printf("%d\n", ans);

    return 0;
}
