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
const int INF = 1 << 30;
const int MAXN = 500;
const int MAXM = 500 * 500;

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
        if (v == T) {
            return true;
        }

        used[v] = true;

        for (int idx: g[v]) {
            if (!used[to[idx]] && cap[idx] - flow[idx] >= curFlow && 
                dfs(to[idx], T, curFlow)) {

                flow[idx] += curFlow;
                flow[idx ^ 1] -= curFlow;

                return true;
            }
        }

        return false;
    }

    int getMaxFlow(int S, int T) {
        int resFlow = 0;
        int curFlow = 1 << 30;

        while (curFlow > 0) {
            memset(used, false, sizeof used);

            if (dfs(S, T, curFlow)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }
        }

        return curFlow;
    }
};

int n;
int x[MAXN], y[MAXN];
MaxFlow maxFlow;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    int S = 0;
    int nextNode = n + 1;

    for (int i = 1; i <= n; i++) {
        maxFlow.addEdge(S, i, INF);
    }


    
    return 0;
}
