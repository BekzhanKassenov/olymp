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

int n;
long long A, s;
long long d[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%I64d", &n, &A);
    
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &d[i]);
        s += d[i];
    }

    for (int i = 0; i < n; i++) {
        int mn = max(0ll, A - s + d[i] - 1);
        int mx = min(d[i], A - n + 1);

        printf("%I64d ", min(d[i], mn + d[i] - mx));
    }

    return 0;
}
