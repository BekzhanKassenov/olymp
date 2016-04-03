/****************************************
**        Solution by NU PTZ 2016      **
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

int n, d, a, b;
int p[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d%d", &n, &d, &a, &b);

    int incr = -1;
    int len = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int shares = 0;

    for (int i = 1; i < n; i++) {
        if (p[i] > p[i - 1]) {
            if (incr == 1) {
                len++;
            } else {
                incr = 1;
                len = 1;
            }
        } else if (p[i] < p[i - 1]) {
            if (incr == 0) {
                len++;
            } else {
                incr = 0;
                len = 1;
            }
        } else {
            incr = -1;
            len = 0;
        }

        if (incr == 1) {
            int cnt = min(d / p[i], len * a);
            shares += cnt;
            d -= p[i] * cnt;
        } else if (incr == 0) {
            int cnt = min(shares, len * b);
            shares -= cnt;
            d += p[i] * cnt;
        }
    }

    printf("%d %d\n", d, shares);

    return 0;
}
