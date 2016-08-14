#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int len;
int digit[20];
bool calced[20][20][2];
long long dp[20][20][2];

long long f(int k, int pos, int cnt, bool smaller) {
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
    long long &ans = dp[pos][cnt][smaller];

    ans = 0;
    int upper = smaller ? 9 : digit[pos];
    for (int d = 0; d <= upper; d++) {
        ans += f(k, pos + 1, cnt + (d == 5), smaller || d < digit[pos]);
    }

    return ans;
}

long long solve(int cnt) {
    long long ans = 0;

    for (int i = 1; i <= digit[0]; i++) {
        ans += f(cnt, 1, i == 5, i < digit[0]);
    }

    for (int pos = 1; pos + 1 <= len; pos++) {
        for (int i = 1; i <= 9; i++) {
            ans += f(cnt, pos + 1, i == 5, true);
        }
    }

    memset(calced, false, sizeof calced);

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    scanf("%lld", &n);

    while (n > 0) {
        digit[len] = n % 10;
        n /= 10;
        len++;
    }

    reverse(digit, digit + len);

    long long ans = 0;
    for (int i = 1; i <= len; i++) {
        ans += i * solve(i);
    }

    printf("%lld\n", ans);

    return 0;
}
