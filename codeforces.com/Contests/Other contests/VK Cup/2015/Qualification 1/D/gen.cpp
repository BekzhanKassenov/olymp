/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "w", stdout);
#endif

    srand(time(NULL));
    n = rand() % 1000 + 1;
    m = rand() + 1;

    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << ((rand() << 16) ^ rand()) << endl;
    }

    for (int i = 1; i <= m; i++) {
        int l = rand() % n;
        int r = l + rand() % (n - l);

        cout << l + 1 << ' ' << r + 1 << endl;
    }

    cout << endl;

    return 0;
}
