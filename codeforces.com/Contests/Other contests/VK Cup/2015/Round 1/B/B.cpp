/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[MAXN], b[MAXN];
int n, ans = INF;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);

        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }
    
    for (int h = 1; h < MAXN; h++) {
        int w = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (a[i] > h) {
                ok = false;
            }

            if (b[i] <= h) {
                w += a[i];
            } else {
                w += b[i];
            }
        }

        if (ok) {
            ans = min(ans, w * h);
        }
    }

    printf("%d\n", ans);

    return 0;
}
