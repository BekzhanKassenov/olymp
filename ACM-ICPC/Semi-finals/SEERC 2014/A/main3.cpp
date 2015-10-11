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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int ans = 0;
        while(true) {
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (a[i] < 0) {
                    a[i] *= -1;
                    a[(i - 1 + n) % n] -= a[i];
                    a[(i + 1) % n] -= a[i];
                    ans++;
                    ok = false;
                    break;
                }
            }

            if (ok) {
                break;
            }
        }                        

        printf("%d\n", ans);
    }

    return 0;
}
