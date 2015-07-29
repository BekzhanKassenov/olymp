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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int base;
int n, mx;
int cnt[1 << 13];
int sum[1 << 13];
int ans;

bool is_leaf(int v) {
    return (1 << base) <= v && v <= n;
}

int dfs(int v) {
    if (is_leaf(v)) {
        return mx - sum[v];
    }

    int left = dfs(2 * v);
    int right = dfs(2 * v + 1);

    int mn = min(left, right);

    ans += abs(left - right);

    return mn;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &base);

    n = (1 << (base + 1)) - 1;
    
    for (int i = 2; i <= n; i++) {
        scanf("%d", &cnt[i]);
        sum[i] = cnt[i] + sum[i / 2];
    }

    for (int i = (1 << base); i < n; i++) {
        mx = max(mx, sum[i]);
    }

    dfs(1);

    printf("%d\n", ans);

    return 0;
}
