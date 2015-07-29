/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "coloring"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 300010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <int> g[maxn];
int n, m, x, color[maxn], par[maxn];
bool can[maxn][4], leaf[maxn];
bool calced[maxn][4];

bool can_paint(int v, int cc) {
    if (color[v] != 0)
        return color[v] == cc;

    if (calced[v][cc] == true)
        return can[v][cc];

    calced[v][cc] = true;

    bool flag = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        bool ff = false;

        for (int j = 1; j <= 3 && !ff; j++) {
            if (j != cc)
                ff |= can_paint(g[v][i], j);
        }

        flag &= ff;
    }

    return can[v][cc] = flag;
}

void paint(int v, int cc) {
    if (color[v] != 0)
        return;

    for (size_t i = 0; i < g[v].size(); i++) {
        for (int j = 1; j <= 3; j++) {
            if (j != cc && can_paint(g[v][i], j)) {
                paint(g[v][i], j);
                break;
            }
        }
    }

    color[v] = cc;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            g[i].clear();
            color[i] = 0;
            leaf[i] = false;

            for (int j = 0; j < 4; j++) {
                can[i][j] = true;
                calced[i][j] = false;
            }
        }


        for (int i = 1; i < n; i++) {
            scanf("%d", &par[i]);
            g[--par[i]].push_back(i);
        }

        scanf("%d", &m);

        for (int i = 0; i < m; i++) {
            scanf("%d", &x);
            scanf("%d", &color[--x]);

            for (int cc = 0; cc < 3; cc++)
                can[x][cc] = cc == color[x];
        }

        bool flag = false;

        for (int cc = 1; cc <= 3 && !flag; cc++) {
            if (can_paint(0, cc)) {
                paint(0, cc);

                puts("YES");

                for (int i = 0; i < n; i++)
                    printf("%d ", color[i]);

                puts("");

                flag = true;
            }
        }

        if (!flag)
            puts("NO");
    }

    return 0;
}
