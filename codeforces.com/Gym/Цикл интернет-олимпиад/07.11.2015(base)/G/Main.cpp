/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "rectangle"

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

int a, b, p;

bool test(int a, int b) {
    if (a > 1) {
        for (int y = 1; y < b; y++) {
            if (2 * a + b + y == p) {
                return true;
            }
        }
    }

    return 3 * a + b == p;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d", &a, &b, &p);

    if (p & 1) {
        puts("NO");
        return 0;
    }

    p /= 2;

    if (test(a, b) || test(b, a)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
