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

int C, Hr, Hb, Wr, Wb;
long long ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d%d", &C, &Hr, &Hb, &Wr, &Wb);
    
    for (int x = 0; x < 10000000 && 1ll * x * Wr <= C; x++) {
        int y = (C - x * Wr) / Wb;

        ans = max(ans, 1ll * Hr * x + 1ll * Hb * y);
    }

    for (int y = 0; y < 10000000 && 1ll * y * Wb <= C; y++) {
        int x = (C - y * Wb) / Wr;

        ans = max(ans, 1ll * Hr * x + 1ll * Hb * y);
    }
    
    printf("%I64d\n", ans);

    return 0;
}
