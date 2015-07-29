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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x, y;
int a[MAXN], t[MAXN];
ll ans;
int cas;

void update(int pos) {
    for (int i = pos; i < n; i |= (i + 1))
        t[i]++;
}

int sum(int pos) {
    int res = 0;

    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    
    return res;
}

int sum(int l, int r) {
    int res = 0;

    if (l > 0)
        res -= sum(l - 1);

    res += sum(r);

    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d%d%d", &n, &x, &y) && (n || x || y)) {
        cas++;
        ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = (1ll * x * i + y) % n;
            t[i] = 0;
        }


        for (int i = 0; i < n; i++) {
            ans += sum(a[i], n - 1);
            update(a[i]);
        }

        printf("Case %d: %I64d\n", cas, ans);
    }
    
    return 0;
}
