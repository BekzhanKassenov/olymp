/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "friends"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1 << 30;
const int MAXN = 210;
const int MAXM = (110 * 110 + 210) * 2;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    // Edges
    int from[MAXM], to[MAXM];
    int flow[MAXM], cap[MAXM];
    int lastEdge;

    bool used[MAXN];
    vector <int> g[MAXN];

    MaxFlow() : lastEdge(0) { }

    void addEdge(int from, int to, int cap) {
        this->from[lastEdge] = from;
        this->to[lastEdge] = to;
        this->flow[lastEdge] = 0;
        this->cap[lastEdge] = cap;
        g[from].push_back(lastEdge++);

        this->from[lastEdge] = to;
        this->to[lastEdge] = from;
        this->flow[lastEdge] = 0;
        this->cap[lastEdge] = 0;
        g[to].push_back(lastEdge++);
    }

    bool dfs(int v, int T, int curFlow) {
        used[v] = true;
        if (v == T) {
            return true;
        }

        for (int idx: g[v]) {
            if (!used[to[idx]] && cap[idx] - flow[idx] >= curFlow && dfs(to[idx], T, curFlow)) {
                flow[idx] += curFlow;
                flow[idx ^ 1] -= curFlow;

                return true;
            }
        }

        return false;
    }

    int getMaxFlow(int S, int T) {
        int curFlow = INF;
        int resFlow = 0;

        while (curFlow > 0) {
            memset(used, false, sizeof(used));

            if (dfs(S, T, curFlow)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }
        }

        return resFlow;
    }
};

int n, m;
int a[MAXN], b[MAXN];
MaxFlow maxFlow;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);

    int sumA = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sumA += a[i];
    }

    int sumB = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        sumB += b[i];
    }

    if (sumA != sumB) {
        puts("NO");
        return 0;
    }

    int S = 0, T = n + m + 1;

    for (int i = 1; i <= n; i++) {
        maxFlow.addEdge(S, i, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            maxFlow.addEdge(i, n + j, 1);
        }
    }

    for (int i = 1; i <= m; i++) {
        maxFlow.addEdge(n + i, T, b[i]);
    }

    int flow = maxFlow.getMaxFlow(S, T);

    if (flow != sumA) {
        // paranoid
        puts("NO");
        return 0;
    }

    puts("YES");
    printf("%d\n", flow);

    for (int i = 0; i < maxFlow.lastEdge; i += 2) {
        if (maxFlow.from[i] != S && maxFlow.to[i] != T && maxFlow.flow[i] != 0) {
            printf("%d %d\n", maxFlow.from[i], maxFlow.to[i] - n);
        }
    }

    return 0;
}
