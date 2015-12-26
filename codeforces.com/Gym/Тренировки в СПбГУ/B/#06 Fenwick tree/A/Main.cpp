/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "rsq"

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

int n, m, x, type, l, r;
long long t[MAXN];

long long sum(int l) {
    long long result = 0;
    for (int i = l; i > 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

void update(int pos, long long val) {
    val -= sum(pos) - sum(pos - 1);

    for (int i = pos; i <= n; i |= i + 1) {
        t[i] += val;
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        update(i, x);
    }

    while (m--) {
        scanf("%d%d%d", &type, &l, &r);

        if (type == 0) {
            printf("%I64d\n", sum(r) - sum(l - 1));
        } else {
            update(l, r);
        }
    }

    return 0;
}
