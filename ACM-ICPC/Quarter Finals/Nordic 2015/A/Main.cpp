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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];
bool used[MAXN];
bool u[MAXN];
int deg[MAXN], lev[MAXN];

void dfs(int v, vector <int>& comp) {
    comp.push_back(v);
    used[v] = true;

    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to, comp);
        }
    }   
}

pair <int, int> get_root(const vector <int>& comp) {
    queue <int> q;
    for (int v: comp) {
        deg[v] = g[v].size();
        lev[v] = 0;
        u[v] = false;
        if (deg[v] < 2) {
            q.push(v);
            u[v] = true;
        }
    }

    int root = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        root = v;

        for (int to: g[v]) {
            if (!u[to]) {
                deg[to]--;

                if (deg[to] < 2) {
                    lev[to] = max(lev[v] + 1, lev[to]);
                    q.push(to);
                    u[to] = true;
                }
            }
        }
    }

    int cnt = 0;
    for (int v: comp) {
        if (lev[v] == lev[root]) {
            cnt++;
        }
    }

    return {root, lev[root] + cnt - 1};
}

bool cmp(const pair <int, int>& a, const pair <int, int>& b) {
    return a.second > b.second;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    if (n == 2) {
        puts("1");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // Run 1 
    // ====================================================================

    vector <int> comp;
    vector <pair <int, int> > root;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, comp);
            root.push_back(get_root(comp));
            comp.clear();
        }
    }

    // Build tree
    // ====================================================================
    sort(all(root), cmp);

    for (size_t i = 1; i < root.size(); i++) {
        int x = root[0].first;
        int y = root[i].first;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // Retrieve ans
    // ====================================================================
    for (int i = 0; i < n; i++) {
        comp.push_back(i);
    }

    int r = get_root(comp).first;

    int mx1 = 0, mx2 = 0;
    for (int to: g[r]) {
        if (lev[to] > mx1) {
            mx2 = mx1;
            mx1 = lev[to];
        } else if (lev[to] > mx2) {
            mx2 = lev[to];
        }
    }

    printf("%d\n", mx1 + mx2 + 2);

    return 0;
}
