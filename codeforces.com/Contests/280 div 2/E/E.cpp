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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
long long dx, dy;
long long invx, invy;
int cnt[MAXN];

long long get_inv(long long x) {
    for (int i = 0; i < n; i++) {
        if (x * i % n == 1) {
            return i;
        }
    }

    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    scanf("%I64d%I64d", &dx, &dy);

    invx = get_inv(dx);
    invy = get_inv(dy);

    for (int i = 0; i < m; i++) {
        long long x, y;
        scanf("%I64d%I64d", &x, &y);

        long long k = (y * invy) % n;
        long long x0 = ((x - k * dx) % n + n) % n;
        cnt[x0]++;
    }

    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (cnt[i] > cnt[pos]) {
            pos = i;
        }
    }

    printf("%d %d\n", pos, 0);

    return 0;
}
