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
const int maxn = 3010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, v;
int a[maxn], x, y, ans, mx;

void make(int pos, int& cur) {
    if (a[pos] >= cur) {
        ans += cur;
        a[pos] -= cur;
        cur = 0;
    } else {
        ans += a[pos];
        cur -= a[pos];
        a[pos] = 0;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &v);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[x] += y;

        mx = max(mx, x);
    }

    for (int i = 1; i <= mx + 1; i++) {
        int cur = v;

        make(i - 1, cur);
        make(i, cur);
    }

    printf("%d\n", ans);

    return 0;
}
