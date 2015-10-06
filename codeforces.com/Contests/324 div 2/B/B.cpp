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

int n, num;
int cnt[10];

int binpow(int base, int p) {
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (1ll * result * base) % MOD;
        }

        base = (1ll * base * base) % MOD;
        p >>= 1;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                cnt[i + j + k]++;
            }
        }
    }

    scanf("%d", &n);

    int ans = binpow(3, 3 * n);
    ans = (ans - binpow(cnt[6], n) + MOD) % MOD;

    printf("%d\n", ans);

    return 0;
}
