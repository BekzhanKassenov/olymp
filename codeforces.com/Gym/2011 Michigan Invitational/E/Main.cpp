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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int caseNum;
vector <int> g[MAXN];
int par[MAXN];
bool sure[MAXN];
bool used[MAXN];

bool bfs() {
    queue <int> q;

    for (int i = 0; i < m; i++) {
        if (sure[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to: g[v]) {
            if (to != par[v]) {
                if (sure[to]) {
                    return false;
                }

                sure[to] = true;
                q.push(to);
                par[to] = v;
            }
        }
    }

    return true;
}

int dfs(int v, int& edge) {
    edge += g[v].size();
    used[v] = true;

    int ans = 1;
    for (int to: g[v]) {
        if (!used[to]) {
            ans += dfs(to, edge);
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
        
    while (scanf("%d%d", &n, &m) && (n || m)) {
        caseNum++;

        for (int i = 0; i < m; i++) {
            g[i].clear();
            sure[i] = false;
            par[i] = -1;
            used[i] = false;
        }   

        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y) {
                sure[x] = true;
            } else {
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }

        if (n > m) {
            printf("Case %d: 0\n", caseNum);
            continue;
        }

        if (!bfs()) {
            printf("Case %d: 0\n", caseNum);
            continue;
        }

        int ans = 1;
        for (int i = 0; i < m; i++) {
            if (!sure[i] && !used[i]) {
                int edgeNum = 0;
                int nodeNum = dfs(i, edgeNum);

                edgeNum /= 2;

                if (edgeNum > nodeNum) {
                    ans = 0;
                } else if (edgeNum == nodeNum) {
                    ans = (1ll * ans * 2) % MOD;
                } else {
                    ans = (1ll * ans * nodeNum) % MOD;
                }
            }
        }

        printf("Case %d: %d\n", caseNum, ans);
    }
    
    return 0;
}
