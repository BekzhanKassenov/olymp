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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int m;
            char c;
            scanf("%d %c\n", &m, &c);

            m += 25;

            if (c == '+') {
                l += m;
            } else {
                if (r == -1) {
                    r = l + m - 1;
                } else {
                    r = min(r, l + m - 1);
                }
            }
        }

        if (r >= l) {
            printf("%d\n", r - l + 1);
        } else {
            puts("0");
        }
    }
    
    return 0;
}
