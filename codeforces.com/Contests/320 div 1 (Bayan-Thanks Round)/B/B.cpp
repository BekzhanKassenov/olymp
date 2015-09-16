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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, x;
long long a[MAXN];
long long pref[MAXN];
long long suff[MAXN];
long long ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &x);

    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        pref[i] = a[i] | pref[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        suff[i] = a[i] | suff[i + 1];
    }

    long long mul = 1;
    for (int i = 1; i <= k; i++) {
        mul *= x;
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, pref[i - 1] | (a[i] * mul) | pref[i + 1]);
    }

    printf("%I64d\n", ans);

    return 0;
}
