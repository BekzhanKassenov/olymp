#include <bits/stdc++.h>

using namespace std;

const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const int MOD = 1000 * 1000 * 1000 + 7;

char let[] = {'A', 'C', 'G', 'T'};
int cnt[4];
int n;
char s[MAXN];


int main() {
    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 4; k++) {
            if (let[k] == s[i]) {
                cnt[k]++;
            }
        }
    }

    vector <long long> dp(n + 1, -INF), numbers(n + 1, 0);
    dp[0] = 0;
    numbers[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 4; k++) {
            if (dp[i + 1] < dp[i] + n * 1ll * cnt[k]) {
                dp[i + 1] = dp[i] + n * 1ll * cnt[k];
                numbers[i + 1] = 0;
            }

            if (dp[i + 1] == dp[i] + n * 1ll * cnt[k]) {
                dp[i + 1] = dp[i] + n * 1ll * cnt[k];
                (numbers[i + 1] += numbers[i]) %= MOD;
            }
        }
    }

    cout << numbers[n];

    return 0;
}
