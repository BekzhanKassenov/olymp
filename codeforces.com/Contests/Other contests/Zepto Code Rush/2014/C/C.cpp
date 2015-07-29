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
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k, w, diff[maxn][maxn], ans;
char s[maxn][11][11];
vector <int> g[maxn];
int mine[maxn], par[maxn];
bool used[maxn];

int get_diff(char s1[11][11], char s2[11][11]) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans += s1[i][j] != s2[i][j];
    }

    ans *= w;

    return ans;
}

void dfs(int v) {
    for (size_t i = 0; i < g[v].size(); i++) {
        printf("%d %d\n", g[v][i], v);
        dfs(g[v][i]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d%d\n", &n, &m, &k, &w);

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++)
            gets(s[i][j]);

        for (int j = 1; j < i; j++)
            diff[i][j] = diff[j][i] = get_diff(s[i], s[j]);
    }

    memset(par, 255, sizeof par);

    for (int i = 1; i <= k; i++) {
        diff[i][0] = diff[0][i] = n * m;
        mine[i] = INF;
    }

    for (int i = 0; i <= k; i++) {
        int v = -1;

        for (int j = 0; j <= k; j++)
            if (!used[j] && (v == -1 || mine[j] < mine[v]))
                v = j;

        used[v] = true;
        ans += mine[v];

        if (par[v] != -1)
            g[par[v]].push_back(v);

        for (int to = 0; to <= k; to++) {
            if (!used[to] && diff[to][v] < mine[to]) {
                mine[to] = diff[to][v];
                par[to] = v;
            }
        }
    }

    printf("%d\n", ans);

    dfs(0);

    return 0;
}
