#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 1 << 30;

struct Edge {
    int to;
    int flow, cap;

    Edge() { }

    Edge(int to, int flow, int cap) : to(to), flow(flow), cap(cap) { }
};

template <int N>
struct Flow {
    int lastE;
    Edge e[10 * N];
    vector <int> g[N];
    bool used[N];

    Flow() : lastE(0) { }

    void addEdge(int from, int to, int cap) {
        e[lastE] = Edge(to, 0, cap);
        g[from].push_back(lastE);
        lastE++;

        e[lastE] = Edge(from, 0, 0); 
        g[to].push_back(lastE);
        lastE++;
    }

    bool dfs(int v, int T, int lim) {
        used[v] = true;

        if (v == T) {
            return true;
        }

        for (size_t i = 0; i < g[v].size(); i++) {
            int idx = g[v][i];
            if (!used[e[idx].to] && e[idx].cap - e[idx].flow >= lim && dfs(e[idx].to, T, lim)) {
                e[idx].flow += lim;
                e[idx ^ 1].flow -= lim;

                return true;
            }
        }
        
        return false;
    }

    int get_max_flow(int from, int to) {
        int lim = INF;
        int ans = 0;

        while (lim > 0) {
            if (dfs(from, to, lim)) {
                ans += lim;
            } else {
                lim >>= 1;
            }

            memset(used, false, sizeof used);
        }

        return ans;
    }
};

int n, m;
int a[40][40];
int r[40], c[40];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    
    for (int j = 0; j < m; j++) {
        scanf("%d", &c[j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    const int N = 2 + n + m + n * m;
    Flow <1000> flow;

    int S = 0, T = N - 1;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                sum += a[i][j];
            } else {
                flow.addEdge(i + 1, n + 1 + i * m + j, INF);
            }
        }

        if (sum > r[i]) {
            puts("-1");
            return 0;
        }

        int cap = r[i] - sum;

        flow.addEdge(S, i + 1, cap);
    }

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] != -1) {
                sum += a[i][j];
            } else {
                flow.addEdge(n + 1 + i * m + j, n + 1 + n * m + j, INF);
            }
        }

        if (sum > c[j]) {
            puts("-1");
            return 0;
        }

        int cap = c[j] - sum;
        flow.addEdge(n + 1 + n * m + j, T, cap);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                sum += a[i][j];
            }
        }
    }

    printf("%d\n", flow.get_max_flow(S, T) + sum);

    return 0;
}
