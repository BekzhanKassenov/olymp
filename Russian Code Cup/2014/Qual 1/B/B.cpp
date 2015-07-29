/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int x, y, k, t, T;

ll solve() {
    ll res = 0;

    if (x % y != 0) {
        ll res1 = (x / y + 1) * y - x;



    }

    int cnt = min(t, k);
    res = x + cnt * 1ll * y;

    t -= cnt;
    res += t;

    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d%d", &x, &y, &k, &t);

        printf("%I64d\n", solve());
    }

    return 0;
}
