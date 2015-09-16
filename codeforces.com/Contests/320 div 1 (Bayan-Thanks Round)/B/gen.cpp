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
const int MOD = 1000 * 1000 * 1000;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, x;
long long a[MAXN];

int main() {
    srand(time(NULL));


    n = rand() % 20 + 1;
    k = rand() % 6;
    x = rand() % 7 + 2;

    cout << n << ' ' << k << ' ' << x << endl;

    for (int i = 0; i < n; i++) {
        cout << ((rand() << 16) ^ rand()) % MOD << ' ';
    }

    return 0;
}
