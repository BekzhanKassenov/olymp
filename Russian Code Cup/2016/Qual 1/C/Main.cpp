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
const int MAXN = 100100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, a[MAXN];

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, a + n);
        
        int ans = a[0];
        int pos = -1;
        for (int i = 1; i < n; i++) {
            if (gcd(a[i], a[0]) == 1) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            printf("%d\n", ans);
            continue;
        } else {
            bool one = false;
            for (int i = pos + 1; i < n; i++) {
                if (gcd(a[i], a[0]) == 1 && gcd(a[i], a[pos]) == 1) {
                    one = true;
                }
            }

            if (one) {
                puts("1");
            } else {
                printf("%d\n", ans);
            }
        }
    }
    
    return 0;
}
