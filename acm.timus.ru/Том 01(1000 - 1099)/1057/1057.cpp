#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// Input data
long long x, y;
int k, b;

// First method
long long pw[110];
int len;

int go(int pos, int cnt, long long num) {
    if (num < 0) {
        return 0;
    }

    if (pos >= len) {
        return cnt == 0 && x <= num && num <= y;
    }

    int ans = 0;
    ans += go(pos + 1, cnt - 1, num + pw[pos]);
    ans += go(pos + 1, cnt, num);

    return ans;
}

void solve1() {
    pw[0] = 1;
    for (int i = 1; i < 100; i++) {
        pw[i] = pw[i - 1] * b;
        if (pw[i] > y) {
            pw[i + 1] = pw[i] * b;
            len = i;
            break;
        }
    }

    printf("%d\n", go(0, k, 0));
}

// Second method

const int MAXN = 33;

int dp[MAXN][MAXN][2];
bool calced[MAXN][MAXN][2];

int f(int N, int len, int pos, int cnt, bool smaller) {
    int& ans = dp[pos][cnt][smaller];

    if (calced[pos][cnt][smaller]) {
        return ans;
    }

    calced[pos][cnt][smaller] = true;

    if (cnt > k) {
        return ans = 0;
    }

    if (pos >= len) {
        return ans = (cnt == k);
    }

    int ndig = (N >> (len - pos - 1)) & 1;

    int upper = ndig;
    if (smaller) {
        upper = 1;
    }

    for (int dig = 0; dig <= upper; dig++) {
        bool nsmaller = smaller;
        if (!smaller) {
            nsmaller = dig < ndig;
        }

        ans += f(N, len, pos + 1, cnt + (dig == 1), nsmaller);
    }

    return ans;
}

int F(int x) {
    memset(calced, false, sizeof calced);
    memset(dp, 0, sizeof dp);

    int len = 0;
    for (int i = 0; (1ll << i) <= x; i++) {
        len++;
    }

    int ans = f(x, len, 1, 1, false);
    for (int i = 1; i + 1 <= len; i++) {
        ans += f(x, len, i + 1, 1, true);
    }

    return ans;
}

void solve2() {
    printf("%d\n", F(y) - F(x - 1));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%lld%lld", &x, &y);
    scanf("%d%d", &k, &b);

    if (b != 2) {
        solve1();
    } else {
        solve2();
    }

    return 0;
}
