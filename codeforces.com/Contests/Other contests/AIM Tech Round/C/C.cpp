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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
bool g[MAXN][MAXN];
int color[MAXN];
char res[MAXN];

int dfs(int v, int c = 1) {
    int ans = 1;
    color[v] = c;

    for (int i = 1; i <= n; i++) {
        if (!g[v][i]) {
            continue;
        }

        if (!color[i]) {
            int temp = dfs(i, 3 - c);
            if (temp == -1) {
                return -1;
            }

            ans += temp;
        } else if (color[i] == color[v]) {
            return -1;
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = true;
    }

    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) {
            deg += g[i][j];
        }

        if (deg == n - 1) {
            color[i] = 3;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                g[i][j] ^= true;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            int res = dfs(i);
            if (res == -1) {
                puts("No");
                return 0;
            }

            if (res > 1) {
                cnt++;
            }
        }
    }

    if (cnt > 1) {
        puts("No");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        switch (color[i]) {
            case 1:
                res[i] = 'a';
                break;

            case 2:
                res[i] = 'c';
                break;

            case 3:
                res[i] = 'b';
                break;

            default:
                break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                g[i][j] ^= true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int diff = res[i];
            diff = abs(diff - res[j]);
            int edge = diff <= 1;
            if (g[i][j] != edge) {
                puts("No");
                return 0;
            }
        }
    }

    puts("Yes");
    puts(res + 1);

    return 0;
}
