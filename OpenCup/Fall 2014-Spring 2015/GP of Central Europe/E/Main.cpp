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

int gcd (int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }

    int x1, y1;
    int d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int T;
set <int> used;
int p, q, n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &p, &q, &n);
        
        int x, y;
        int g = gcd(p, q, x, y);

        if (n % g != 0) {
            puts("R");
            continue;
        }

        x *= n / g;
        y *= n / g;

        int temp = (q - p) / g;

        if ((x + y) % temp == 0) {
            puts("E");
        } else {
            puts("P");
        }
    }
                    
    return 0;
}
