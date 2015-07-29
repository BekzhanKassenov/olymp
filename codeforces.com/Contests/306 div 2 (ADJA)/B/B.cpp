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

int n, l, r, x;
int c[21], ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &l, &r, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) < 2) {
            continue;
        }
        int mn = -1, mx = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (mn == -1 || c[mn] > c[i]) {
                    mn = i;
                }
                
                if (mx == -1 || c[mx] < c[i]) {
                    mx = i;
                }

                sum += c[i];
            }
        }

        if (l <= sum && sum <= r && c[mx] - c[mn] >= x) {
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
