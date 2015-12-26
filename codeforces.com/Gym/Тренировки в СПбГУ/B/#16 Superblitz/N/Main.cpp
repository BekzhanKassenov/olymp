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
const int MAXN = 20010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, x, y, ans;
int tin[MAXN], fup[MAXN], timer;
bool used[MAXN], is_cutpoint[MAXN];
vector <int> g[MAXN];
int compnum;

void dfs(int v, int par = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int childnum = 0;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (to == par) {
            continue;
        }

        if (!used[to]) {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            childnum++;

            if (fup[to] >= tin[v] && par != -1 && !is_cutpoint[v]) {
                is_cutpoint[v] = true;
                ans++;
            }
        } else {
            fup[v] = min(fup[v], tin[to]);
        }
    }

    if (par == -1 && childnum > 1) {
        is_cutpoint[v] = true;
        ans++;
    }
}

// 5-th test : m == 443 && n == 100
int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
            compnum++;
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        if (is_cutpoint[i]) {
            printf("%d%c", i, " \n"[i == n]);
        }
    }
    
    return 0;
}
