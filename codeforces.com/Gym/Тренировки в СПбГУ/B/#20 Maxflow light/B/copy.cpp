#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 2 * 10010;
const int MAXM = 4 * 110000;
const long long INF = 1ll << 62;

struct Queue {
    int q[MAXN];
    int head, tail;

    Queue() : head(0), tail(0) { }

    void clear() {
        head = tail = 0;
    }

    void push(int v) {
        q[head++] = v;
    }

    int front() const {
        return q[tail];
    }

    void pop() {
        if (tail < head) {
            tail++;
        }
    }

    bool empty() const {
        return tail >= head;
    }
};

struct Dinic {
    int to[MAXM];
    long long flow[MAXM];
    long long cap[MAXM];
    int lastE;

    vector <int> g[MAXN];
    size_t ptr[MAXN];
    int level[MAXN];
    Queue q;

    Dinic() : lastE(0) { }

    void addEdge(int from, int to, long long cap) {
        this->to[lastE] = to;
        this->flow[lastE] = 0;
        this->cap[lastE] = cap;
        g[from].push_back(lastE);
        lastE++;

        this->to[lastE] = from;
        this->flow[lastE] = 0;
        this->cap[lastE] = 0;
        g[to].push_back(lastE);
        lastE++;
    }

    bool bfs(int S, int T, long long addFlow) {
        memset(level, 255, sizeof level);
        q.clear();

        q.push(S);
        level[S] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (size_t i = 0; i < g[v].size(); i++) {
                int idx = g[v][i];
                
                if (level[to[idx]] == -1 && cap[idx] - flow[idx] >= addFlow) {
                    level[to[idx]] = level[v] + 1;
                    q.push(to[idx]);
                }
            }
        }

        return level[T] != -1;
    }

    bool dfs(int v, int T, long long addFlow) {
        if (v == T) {
            return true;
        }

        for (; ptr[v] < g[v].size(); ptr[v]++) {
            int idx = g[v][ptr[v]];

            if (cap[idx] - flow[idx] >= addFlow && level[to[idx]] == level[v] + 1 &&
                dfs(to[idx], T, addFlow)) {
                
                flow[idx] += addFlow;
                flow[idx ^ 1] -= addFlow;
                return true;
            }
        }

        return false;
    }

    long long getMaxFlow(int S, int T) {
        long long flow = 0;
        long long addFlow = INF;

        while (addFlow > 0) {
            while (bfs(S, T, addFlow)) {
                memset(ptr, 0, sizeof ptr);
                while (dfs(S, T, addFlow)) {
                    flow += addFlow;
                }
            }
        
            addFlow >>= 1;
        }

        return flow;
    }
};

int n, m, x, y;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    int S = 0, T = 2 * n + 1;
    Dinic flow;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        flow.addEdge(S, i, x);
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        scanf("%d", &x);
        flow.addEdge(i, T, x);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        flow.addEdge(x, n + y, INF);
        flow.addEdge(n + y, x, INF);
    }

    printf("%I64d\n", flow.getMaxFlow(S, T));

    return 0;
}
