/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "defense"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 40100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int m, n, k, a, b;
bool w[MAXN], h[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d", &m, &n, &k);

    w[0] = w[m + 1] = true;
    h[0] = h[n + 1] = true;
    
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        w[a] = true;
        h[b] = true;
    }

    int maxw = 0, curw = 0;
    for (int i = 0; i <= m + 1; i++) {
        if (!w[i]) {
            curw++;
        } else {
            maxw = max(maxw, curw);
            curw = 0;
        }
    }

    int maxh = 0, curh = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (!h[i]) {
            curh++;
        } else {
            maxh = max(maxh, curh);
            curh = 0;
        }
    }

    printf("%I64d\n", 1ll * maxw * maxh);


    return 0;
}
