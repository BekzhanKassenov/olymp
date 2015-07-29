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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n;
int dist[MAXN][MAXN];
int pos[MAXN][MAXN];
int par[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                scanf("%d", &dist[i][j]);
                pos[i][dist[i][j]] = j;
            }

        memset(par, -1, sizeof par);

        for (int i = 2; i <= n; i++) {
            int pr = 1;

            int vert = dist[1][i];

            for (int j = 2; j < i; j++) {
                int test = dist[1][j];

                if (pos[vert][pr] > pos[vert][test])
                    pr = test;
            }

            par[vert] = pr;
        }

        for (int i = 2; i <= n; i++)
            printf("%d %d\n", i, par[i]);

        puts("");
    }
    
    return 0;
}
