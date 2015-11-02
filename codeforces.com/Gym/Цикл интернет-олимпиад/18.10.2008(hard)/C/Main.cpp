/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "chip"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;
const int MAXM = MAXN * MAXN * 4;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    int from[MAXM], to[MAXM];
    int flow[MAXM], cap[MAXM];
    int lastEdge;

    vector <int> g[MAXN];

    bool used[MAXN];

    MaxFlow() : lastEdge(0) { }

    void addEdge(int from, int to, int cap) {
        this->from[lastEdge] = from;
        this->to[lastEdge] = to;
        this->cap[lastEdge] = cap;
        this->flow[lastEdge] = 0;
        g[from].push_back(lastEdge++);

        this->from[lastEdge] = to;
        this->to[lastEdge] = from;
        this->cap[lastEdge] = 0;
        this->flow[lastEdge] = 0;
        g[to].push_back(lastEdge++);
    }

    bool dfs(int v, int lim, int T) {
        if (v == T) {
            return true;
        }

        used[v] = true;

        for (int idx: g[v]) {
            if (!used[to[idx]] && cap[idx] - flow[idx] >= lim && dfs(to[idx], lim, T)) {
                flow[idx] += lim;
                flow[idx ^ 1] -= lim;
                return true;
            }
        }

        return false;
    }   

    int getMaxFlow(int S, int T) {
        int curFlow = 1 << 30;
        int resFlow = 0;

        while (curFlow > 0) {
            memset(used, false, sizeof used);

            if (dfs(S, curFlow, T)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }
        }

        return resFlow;
    }
};

MaxFlow maxFlow;
int n, m, h;
int a[MAXN], b[MAXN], x[MAXN];
char s[MAXN][MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d", &n, &m, &h);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }   

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        x[i] = n - b[i] * h;

        if (x[i] < 0) {
            puts("inconsistent");
            return 0;
        }
    }

    int S = (n + m);
    int T = (n + m) + 1;

    for (int i = 0; i < n; i++) {
        maxFlow.addEdge(S, i, a[i]);
    }

    for (int i = 0; i < m; i++) {
        maxFlow.addEdge(m + i, T, x[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxFlow.addEdge(i, m + j, 1);
        }
    }

    maxFlow.getMaxFlow(S, T);

    for (int i = 0; i < maxFlow.lastEdge; i += 2) {
        if (maxFlow.from[i] == S && maxFlow.flow[i] != maxFlow.cap[i]) {
            //cerr << maxFlow.to[i] << endl;
            puts("inconsistent");
            return 0;
        } else if (maxFlow.to[i] == T && maxFlow.flow[i] != maxFlow.cap[i]) {
            puts("inconsistent");
            return 0;
        } else if (maxFlow.flow[i] == maxFlow.cap[i]) {
            s[maxFlow.from[i]][maxFlow.to[i] - m] = '*';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '\0') {
                s[i][j] = '+';
                for (int k = i + 1; k < i + h - 1; k++) {
                    if (s[k][j] == '*') {
                        cerr << "FATAL ERROR! TERMINATING DUE TO (wrong flow detected)";
                        puts("inconsistent");
                        return 0;
                    }
                    s[k][j] = '|';
                }
                s[i + h - 1][j] = '+';
            }
        }
    }


    for (int i = 0; i < n; i++) {
        puts(s[i]);
    }

    return 0;
}
