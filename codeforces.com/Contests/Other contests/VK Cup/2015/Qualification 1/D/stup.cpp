/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN], l, r;
int next[MAXN];
map <int, int> pos;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
    	next[pos[a[i]]] = i;
    	pos[a[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        int ans = INF;

        for (int j = l; j <= r; j++) {
            if (next[j] <= r && next[j] != 0) {
                ans = min(ans, next[j] - j);
            }
        }

        if (ans != INF) {
            printf("%d\n", ans);
        } else {
            puts("-1");
        }
    }

    return 0;
}
