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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN], b[MAXN], f[MAXN];
int posf[MAXN], cnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        posf[f[i]] = i;
        cnt[f[i]]++;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    bool ambigious = false;
    for (int i = 1; i <= m; i++) {
        if (posf[b[i]] == 0) {
            puts("Impossible");
            return 0;
        }

        a[i] = posf[b[i]];

        if (cnt[b[i]] > 1) {
            ambigious = true;
        }
    }

    if (ambigious) {
        puts("Ambiguity");
        return 0;
    }

    puts("Possible");
    for (int i = 1; i <= m; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
