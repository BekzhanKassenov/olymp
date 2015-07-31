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
const int MAXN = 1000 * 1000 + 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x, ans;
int dp[MAXN];
bool has[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        has[x] = true;
    }

    for (int i = 1; i < MAXN; i++) {
        if (!has[i]) {
            continue;
        }

        dp[i]++;

        for (int j = i + i; j < MAXN; j += i) {
            dp[j] = max(dp[i], dp[j]);
        }

        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    
    return 0;
}
