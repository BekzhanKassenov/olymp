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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    srand(time(NULL));
    int n = rand() % 12 + 1;
    int q = rand() % 12 + 1;

    printf("%d %d\n", n, q);

    while (q--) {
        int type = rand() % 3 + 1;
        int x = rand() % n + 1;
        int y = rand() % n + 1;

        printf("%d %d %d\n", type, x, y);
    }
    
    return 0;
}
                             