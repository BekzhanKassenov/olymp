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

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    if (n == 4) {
        puts("4");
        puts("2 4 1 3");
    } else if (n > 3) {
        printf("%d\n", n);

        for (int i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }

        for (int i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }
    } else if (n == 3) {
        puts("2");
        puts("1 3");
    } else {
        puts("1");
        puts("1");
    }
    
    return 0;
}
