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

int n, m;
int cnt[11];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        
        cnt[x]++;
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            ans += 1ll * cnt[i] * cnt[j];
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
