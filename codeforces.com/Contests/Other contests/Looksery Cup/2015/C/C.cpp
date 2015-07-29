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

int n, k;
int a[MAXN];
int zero, one, game, sum;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] & 1) {
            one++;
        } else {
            zero++;
        }
    }

    sum = one;

    game = n - k;

    if (one >= game && zero >= game) {
        if (game & 1) {
            puts("Stannis");
        } else {
            puts("Daenerys");
        }

        return 0;
    }




    return 0;
}
