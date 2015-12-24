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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool calced[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;
int a[MAXN];

bool pal(int l, int r) {
    while (l < r) {
        if (a[l] != a[r]) {
            return false;
        }

        l++, r--;
    }

    return true;
}

int calc(int l, int r) {
    if (l > r) {
        return 0;
    }

    if (calced[l][r]) {
        return dp[l][r];
    }

    calced[l][r] = true;
    int& ans = dp[l][r];
    ans = 1 + calc(l + 1, r);

    if (pal(l, r)) {
        return ans = 1;
    }

    if (l + 1 <= r && a[l] == a[l + 1]) {
        ans = min(ans, 1 + calc(l + 2, r));
    }

    for (int k = l + 2; k <= r; k++) {
        if (a[l] == a[k]) {
            ans = min(ans, calc(l + 1, k - 1) + calc(k + 1, r));
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", calc(1, n));

    return 0;
}
