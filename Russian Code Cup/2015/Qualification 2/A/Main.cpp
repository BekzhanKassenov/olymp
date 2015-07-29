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
int a, b, k;

int get(int n) {
    if (n > 99) {
        return 99;
    }
    
    return n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &a, &b, &k);
        
        bool found = false;
        int ans = 0;

        if (a > b) {
            swap(a, b);
        }

        if (get(b) == get(a) * k) {
            puts("0");
            found = true;
        }

        if (a > 99 && b > 99) {
            int diff = a - 99;

            a -= diff;
            b -= diff;
            ans += diff;
        }

        while (!found && a > 0 && b > 0) {
            if (get(b) == get(a) * k) {
                printf("%d\n", ans);
                found = true;
            }

            a--, b--;
            ans++;
        }

        if (!found) {
            puts("-1");
        }
    }
    
    return 0;
}
