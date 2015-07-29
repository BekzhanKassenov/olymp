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

int T;
long long l, r, ansnum;
int anspopcount;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%I64d%I64d", &l, &r);

        if (__builtin_popcountll(l) >= __builtin_popcountll(r)) {
            anspopcount = __builtin_popcountll(l);
            ansnum = l;
        } else {
            anspopcount = __builtin_popcountll(r);
            ansnum = r;
        }
        
        for (int i = 0; l <= r; i++) {
            if (!(l & (1ll << i))) {
                l |= (1ll << i);

                if (l <= r && __builtin_popcountll(l) >= anspopcount) {
                    anspopcount = __builtin_popcountll(l);
                    ansnum = l;
                }
            }
        }
        
        printf("%I64d\n", ansnum);
    }

    return 0;
}
