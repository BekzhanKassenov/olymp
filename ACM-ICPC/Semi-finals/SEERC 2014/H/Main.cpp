/****************************************
**          Solution by NU #2          **
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

int n, m;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &m, &n) == 2) {

        int ans = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) {
                for (int k = j; k <= m; k++) {
                    if (sqr(i) + sqr(j) == sqr(k)) {
                        ans++;
                    }
                }
            }
        }

        ans += (n - 1) * (m + 1);

        printf("%d\n", ans);
    }

    return 0;
}
