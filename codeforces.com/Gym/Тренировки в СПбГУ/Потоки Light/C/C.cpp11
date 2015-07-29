#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 110;

struct Queue {
    int q[MAXN];
    int head, tail;

    Queue() : head(0), tail(0) { }

    void push(int val) {
        q[head++] = val;
    }

    int front() const {
        return q[tail];
    }

    void pop() {
        tail++;
    }

    bool empty() {
        return tail >= head;
    }

    void clear() {
        head = tail = 0;
    }
};

struct Flow {
    int to[4 * MAXN * MAXN];
    int flow[4 * MAXN * MAXN];
    int cap[4 * MAXN * MAXN];

    int lastE;
    size_t ptr[MAXN];
    int level[MAXN];
    bool used[MAXN];
    vector <int> g[MAXN];
    static const int INF = 1 << 30;
    Queue q;

    Flow() : lastE(0) { }

    void addEdge(int f, int t, int c) {
        to[lastE] = t;
        flow[lastE] = 0;
        cap[lastE] = c;
        g[f].push_back(lastE);
        lastE++;

        to[lastE] = f;
        flow[lastE] = 0;
        cap[lastE] = 0;
        g[t].push_back(lastE);
        lastE++;
    }

    void clearFlow() {
        for (int i = 0; i < lastE; i++) {
            flow[i] = 0;
        }
    }

    bool bfs(int S, int T, int addFlow) {
        q.clear();
        q.push(S);
        memset(level, 255, sizeof level);
        level[S] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (size_t i = 0; i < g[v].size(); i++) {
                int idx = g[v][i];

                if (cap[idx] - flow[idx] >= addFlow && level[to[idx]] == -1) {
                    //printf("%d-->%d, %d %d\n", v, to[idx], flow[idx], cap[idx]);
                    level[to[idx]] = level[v] + 1;
                    q.push(to[idx]);
                }
            }
        }

        return level[T] != -1;
    }
    
    bool dfs(int v, int T, int addFlow) {
        if (v == T) {
            return true;
        }

        for (; ptr[v] < g[v].size(); ptr[v]++) {
            int idx = g[v][ptr[v]];

            if (level[to[idx]] != level[v] + 1) {
                continue;
            }

            if (cap[idx] - flow[idx] >= addFlow && dfs(to[idx], T, addFlow)) {
                flow[idx] += addFlow;
                flow[idx ^ 1] -= addFlow;
                return true;
            }
        }
        
        return false;
    }

    int getMaxFlow(int S, int T) {
        int flow = 0;

        while (bfs(S, T, 1)) {
            //memset(used, false, sizeof used);
            memset(ptr, 0, sizeof ptr);

            while (dfs(S, T, 1)) {
                flow++;
            }
        }

        return flow;
    }
};

int n, m;
int x, y;
int ans = Flow::INF;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    Flow flow;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--, y--;

        flow.addEdge(x, y, 1);
        flow.addEdge(y, x, 1);
    }
    
    for (int i = 1; i < n; i++) {
        int temp = flow.getMaxFlow(0, i);

        ans = min(ans, temp);
        flow.clearFlow();
    }
    
    printf("%d\n", ans);

    return 0;
}
