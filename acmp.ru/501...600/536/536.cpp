#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 50010;

int n, c, k;
long long MOD, dp[maxn];
bool calced[maxn];      
char s[maxn];

bool ok(int l, int r) {
    if (s[l] == '0') {
        return r - l == 0;
    }

    long long num = 0;

    for (int i = l; i <= r; i++) {
        num *= 10;
        num += s[i] - '0';
    }

    return num <= c;
}

long long solve(int pos) {
    if (pos >= n)
        return 1;

    if (calced[pos])
        return dp[pos];

    calced[pos] = true;

    long long &ans = dp[pos];

    for (int i = pos; i < n && ok(pos, i); i++) {
        ans += solve(i + 1);
        ans %= MOD;
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d\n", &n, &c, &k);
    gets(s);

    MOD = 1;

    for (int i = 0; i < k; i++)
        MOD *= 10;

    printf("%I64d\n", solve(0));

    return 0;
}
            