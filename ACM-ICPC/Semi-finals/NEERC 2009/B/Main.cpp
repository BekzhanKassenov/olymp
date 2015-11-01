/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "business"

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

int m;
long long n;
long long u, d, ans = 1ll * INF * INF;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%I64d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%I64d%I64d", &u, &d);
        long long num = n * d;
        long long den = u + d;
        long long x = (num + den - 1) / den;

        if (u * x - (n - x) * d == 0) {
            x++;
        }

        ans = min(ans, u * x - (n - x) * d);
    }


    printf("%I64d\n", ans);

    return 0;
}
