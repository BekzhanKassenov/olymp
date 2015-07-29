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
const int MAXN = 100010;
const int MAXH = 500;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int r, g;
bool calced[MAXN][MAXH];
int dp[MAXN][MAXH];

int get_h(int n) {
    int l = 0, r = n;

    n *= 2;

    while (l <= r) {
        int mid = (l + r) / 2;

        long long num = mid * 1ll * (mid + 1);

        if (num == n)
            return mid;

        if (num < n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int go(int r, int h) {
    if (h == 0) {
        if (r == 0)
            return 1;

        return 0;
    }

    if (calced[r][h])
        return dp[r][h];

    calced[r][h] = true;

    dp[r][h] = go(r, h - 1);

    if (r - h >= 0) {
        dp[r][h] += go(r - h, h - 1);
        dp[r][h] %= MOD;
    }

    return dp[r][h];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &r, &g);
    
    int h = get_h(r + g);

    if (h == -1) {
        puts("0");
        return 0;
    }

    if (r == 0)
        swap(r, g);


    printf("%d\n", go(r, h));

    return 0;
}
