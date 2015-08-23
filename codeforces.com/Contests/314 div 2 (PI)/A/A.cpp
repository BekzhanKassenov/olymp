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

int n;
int x[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < n; i++) {
        int mx = max(abs(x[i] - x[0]), abs(x[i] - x[n - 1]));
        int mn = INF;

        if (i > 0) {
            mn = min(mn, abs(x[i] - x[i - 1]));
        }

        if (i + 1 < n) {
            mn = min(mn, abs(x[i] - x[i + 1]));
        }

        printf("%d %d\n", mn, mx);
    }
    
    return 0;
}
