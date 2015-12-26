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
const int MAXN = 135 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
    srand(time(NULL));
    int n = rand() % 10 + 1;
    int m = rand() % 10 + 1;

    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("%d%c", rand() % m + 1, " \n"[i == n - 1]);
    }

    return 0;
}
