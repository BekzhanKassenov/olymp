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
const int MAXN = 200;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, root;
int lca[MAXN][MAXN];
int par[MAXN];
bool used[MAXN];
int depth[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
        
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &lca[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 2; j <= n; j++) {
            if (lca[i][j] != lca[i][1])
                flag = false;
        }

        if (flag) {
            root = i;
            break;
        }
    }

    used[root] = true;

    for (int q = 1; q < n; q++) {
        for (int i = 1; i <= n; i++) {
            if (used[i])
                continue;
            
            bool flag = true;
            for (int j = 1; j <= n; j++) {
                if (!used[lca[i][j]] && lca[i][j] != i) {
                    flag = false;
                }
            }

            if (!flag)
                continue;

            int dpth = 0, res = root;

            for (int j = 1; j <= n; j++) {
                if (lca[i][j] != i && depth[lca[i][j]] > dpth) {
                    dpth = depth[lca[i][j]];
                    res = lca[i][j];
                }
            }

            par[i] = res;
            depth[i] = depth[res] + 1;
            used[i] = true;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", par[i]);
    
    return 0;
}
