/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "sequence"

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

int x, y, z, w;
int n, k;
int a[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d%d", &x, &y, &z, &w);
    scanf("%d%d", &n, &k);

    a[1] = w;
    for (int i = 2; i <= n; i++) {
        a[i] = (1ll * x * a[i - 1] + y) % z;
    }

    sort(a + 1, a + 1 + n);
    printf("%d\n", a[k]);

    return 0;
}
