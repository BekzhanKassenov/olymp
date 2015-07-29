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
const int MAXN = 15;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q[MAXN], c[MAXN], p[MAXN];
int ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = max(cnt, (q[i] + c[i] - 1) / c[i]);
    }

    for (int i = 0; i < n; i++) {
        ans += (cnt * c[i] - q[i]) * p[i];
    }

    printf("%d\n", ans);

    return 0;
}
