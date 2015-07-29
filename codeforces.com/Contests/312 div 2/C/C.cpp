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

int n, ans = INF;
long long a[MAXN], temp[MAXN];

int get_dist(long long from, long long to) {
    int res = 0;
    
    assert(__builtin_popcountll(from) >= __builtin_popcountll(to));

    while (__builtin_popcountll(from) > __builtin_popcountll(to)) {
        res++;
        from >>= 1;
    }

    while (from > to) {
        res++;
        from >>= 1;
    }

    while (from < to) {
        res++;
        from <<= 1;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        temp[i] = a[i];

        while (!(temp[i] & (1 << 25))) {
            temp[i] <<= 1;
        }
    }

    long long pref = temp[0];

    for (int i = 0; i < n; i++) {
        pref &= temp[i];
    }

    while (!(pref & 1)) {
        pref >>= 1;
    }

    while (pref < (1ll << 35)) {
        int dist = 0;

        for (int i = 0; i < n; i++) {
            dist += get_dist(a[i], pref);
        }
        
        ans = min(ans, dist);
        pref <<= 1;
    }

    printf("%d\n", ans);
    
    return 0;
}
