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

int n, h, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &h, &k);

    int cur = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        int t = 0;
        if (cur + x > h) {
            t = (cur + x - h + k - 1) / k;
        }

        ans += t;
        cur = max(cur - k * t, 0);
        cur += x;
    }

    ans += (cur + k - 1) / k;
    
    printf("%lld\n", ans);

    return 0;
}
