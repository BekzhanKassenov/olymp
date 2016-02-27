/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000;
const int MAXN = 410;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum PARENT {
    TOP,
    LEFT,
    BAD
};

int n, k, W;
int color[MAXN][MAXN];
long long w[MAXN][MAXN];
long long dist[MAXN][MAXN];
PARENT par[MAXN][MAXN];
vector <pair <int, int> > path;

bool has(int mask, int pos) {
    return (mask & (1 << pos)) != 0;
}

bool solve(int mask) {
    if (!has(mask, color[0][0])) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            par[i][j] = BAD;
        }
    }

    dist[0][0] = w[0][0];

    for (int j = 1; j < n && has(mask, color[0][j]); j++) {
        dist[0][j] = dist[0][j - 1] + w[0][j];
        par[0][j] = LEFT;
    }

    for (int i = 1; i < n && has(mask, color[i][0]); i++) {
        dist[i][0] = dist[i - 1][0] + w[i][0];
        par[i][0] = TOP;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (!has(mask, color[i][j])) {
                continue;
            }

            if (par[i - 1][j] != BAD && dist[i - 1][j] + w[i][j] < dist[i][j]) {
                dist[i][j] = dist[i - 1][j] + w[i][j];
                par[i][j] = TOP;
            }

            if (par[i][j - 1] != BAD && dist[i][j - 1] + w[i][j] < dist[i][j]) {
                dist[i][j] = dist[i][j - 1] + w[i][j];
                par[i][j] = LEFT;
            }
        }
    }

    return dist[n - 1][n - 1] <= W;
}

void restore(vector <pair <int, int> >& path) {
    int ii = n - 1, jj = n - 1;
    path.clear();

    for (int i = 0; i < 2 * n - 1; i++) {
        path.emplace_back(ii + 1, jj + 1);
        if (par[ii][jj] == TOP) {
            ii--;
        } else {
            jj--;
        }
    }

    reverse(all(path));
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &W);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(I64, &w[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &color[i][j]);
            color[i][j]--;
        }
    }

    int ans = k + 1;
    for (int mask = 1; mask < (1 << k); mask++){
        if (solve(mask) && __builtin_popcount(mask) < ans) {
            ans = __builtin_popcount(mask);
            restore(path);
        }
    }

    if (ans != k + 1) {
        printf("%d\n", ans);
        for (pair <int, int> p: path) {
            printf("%d %d ", p.first, p.second);
        }
    } else {
        puts("-1");
    }

    return 0;
}
