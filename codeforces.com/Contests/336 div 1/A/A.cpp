/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int mem1[MAXN + 10], mem2[MAXN + 10], mem3[MAXN + 10];
int *power = mem1 + 3;
int *dp = mem2 + 3;
int *cnt = mem3 + 3;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        power[x] = y;
    }

    for (int i = 0; i < MAXN; i++) {
        cnt[i] = cnt[i - 1];

        if (power[i] != 0) {
            cnt[i]++;
        }
    }

    for (int i = 0; i < MAXN; i++) {
        if (power[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            int l = max(i - power[i] - 1, -1);
            dp[i] = dp[l] + cnt[i - 1] - cnt[l];
        }
    }

    int ans = dp[MAXN - 1];

    for (int i = 0; i < MAXN; i++) {
        if (power[i] != 0) {
            int cntr = cnt[MAXN - 1] - cnt[i - 1];
            ans = min(ans, cntr + dp[i - 1]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
