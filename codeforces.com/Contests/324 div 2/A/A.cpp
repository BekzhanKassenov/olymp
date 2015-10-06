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

int n, t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &t);

    if (t == 10) {
        if (n == 1) {
            puts("-1");
        } else {
            putchar('1');

            for (int i = 0; i < n - 1; i++) {
                putchar('0');
            }

            putchar('\n');
        }

        return 0;
    }

    printf("%d", t);
    for (int i = 0; i < n - 1; i++) {
        putchar('0');
    }

    putchar('\n');
    
    return 0;
}
