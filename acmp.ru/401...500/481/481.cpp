#include <cstdio>
#include <cstring>

const int MAXN = 50;

int dp[MAXN][MAXN];
bool calced[MAXN][MAXN];
int n;
char s[MAXN];

int calc(int l, int r) {
    if (l > r)
        return 1;

    if (l == r) 
        return 1;

    if (r - l == 1) {
        if (s[l] == s[r])
            return 3;

        return 2;
    }

    if (calced[l][r])
        return dp[l][r];

    calced[l][r] = true;
    dp[l][r] = calc(l + 1, r) + calc(l, r - 1) - calc(l + 1, r - 1);

    if (s[l] == s[r])
        dp[l][r] += calc(l + 1, r - 1) + 1;

    return dp[l][r];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    n = strlen(s);

    printf("%d", calc(0, n - 1));

    return 0;
}
