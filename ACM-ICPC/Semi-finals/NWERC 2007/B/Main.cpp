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
const int INF = 1 << 30;
const int MAXN = 210;
const int MAXM = MAXN * MAXN * 2;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    // Edges
    int from[MAXM], to[MAXM];
    int flow[MAXM], cap[MAXM];
    int lastEdge;

    vector <int> g[MAXN];
    bool used[MAXN];
    int N;

    void clear(int N) {
        this->N = N;
        lastEdge = 0;

        for (int i = 0; i < N; i++) {
            g[i].clear();
            used[i] = false;
        }
    }

    void clearFlow() {
        for (int i = 0; i < lastEdge; i++) {
            flow[i] = 0;
        }
    }

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

    void popEdge() {
        g[from[lastEdge - 1]].pop_back();
        g[from[lastEdge - 2]].pop_back();
        lastEdge -= 2;
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
            memset(used, false, sizeof(used[0]) * N);

            if (dfs(S, T, curFlow)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }
        }

        return resFlow;
    }
};

int T;
MaxFlow maxFlow;
int N;
double D;
int x[MAXN], y[MAXN], n[MAXN], m[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%lf", &N, &D);

        int sum = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d%d%d", &x[i], &y[i], &n[i], &m[i]);
            sum += n[i];
        }

        int S = 0, T = 2 * N + 1;
        maxFlow.clear(T + 1);

        for (int i = 1; i <= N; i++) {
            maxFlow.addEdge(S, i, n[i]);
        }

        for (int i = 1; i <= N; i++) {
            maxFlow.addEdge(i, i + N, m[i]);
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i != j && sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= sqr(D)) {
                    maxFlow.addEdge(i + N, j, INF);
                }
            }
        }

        bool found = false;
        for (int i = 1; i <= N; i++) {
            maxFlow.addEdge(i, T, INF);

            int flow = maxFlow.getMaxFlow(S, T);

            if (flow == sum) {
                printf("%d ", i - 1);
                found = true;
            }

            maxFlow.clearFlow();
            maxFlow.popEdge();
        }

        if (!found) {
            puts("-1");
        } else {
            puts("");
        }
    }

    return 0;
}
