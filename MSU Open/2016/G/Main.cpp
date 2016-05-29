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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int binpow(int n, int p, int MOD) {
    int res = 1;

    while (p > 0) {
        if (p & 1) {
            res = (1ll * res * n) % MOD;
        }

        n = (1ll * n * n) % MOD;
        p >>= 1;
    }

    return res;
}

int n;
char s[MAXN];
int nxt[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s) - 1;

    int cur = n;
    int ans1 = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') {
            cur = i;
        } else {
            ans1 += cur - i;
            ans1 %= MOD;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') {
            cnt++;
        }
    }

    int ans2 = (binpow(2, cnt, MOD) - 1 + MOD) % MOD;

    printf("%d %d\n", ans1, ans2);
    
    return 0;
}
