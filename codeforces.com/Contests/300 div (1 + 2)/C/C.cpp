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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int d[MAXN], h[MAXN];
int ans;

bool can(int h1, int h2, int d1, int d2) {
    return abs(h1 - h2) <= d2 - d1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &d[i], &h[i]);
    }

    for (int i = 0; i + 1 < m; i++) {
        if (!can(h[i], h[i + 1], d[i], d[i + 1])) {
            puts("IMPOSSIBLE");
            return 0;
        }

        int l = d[i], r = d[i + 1];
        int res = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            int hh = h[i] + (mid - d[i]);

            if (can(h[i], hh, d[i], mid) &&
                can(hh, h[i + 1], mid, d[i + 1])) {
                l = mid + 1;
                res = max(res, hh);
            } else {
                r = mid - 1;
            }
        }

        ans = max(res, ans);
    }

    ans = max(ans, h[0] + d[0] - 1);
    ans = max(ans, h[m - 1] + n - d[m - 1]);

    printf("%d\n", ans);

    return 0;
}
