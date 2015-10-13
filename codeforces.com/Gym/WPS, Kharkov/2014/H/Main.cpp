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

int n, k, x;
int bit[30];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        for (int j = 0; j < 30; j++) {
            if (x & (1 << j)) {
                bit[j]++;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 30; j++) {
        if (bit[j] % k != 0) {
            ans |= 1 << j;
        }
    }

    printf("%d\n", ans);

    return 0;
}
