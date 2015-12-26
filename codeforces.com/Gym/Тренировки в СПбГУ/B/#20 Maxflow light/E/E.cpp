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
const int MAXR = 110;
const int MAXN = 4 * MAXR * MAXR;
const int MAXE = 10 * MAXN;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    int to[MAXE];
    int flow[MAXE];
    int cap[MAXE];
    int lastE;

    vector <int> g[MAXN];
    bool used[MAXN];
    
    MaxFlow() : lastE(0) { }

    void addEdge(int from, int to, int cap) {
        //cout << from << ' ' << to << ' ' << cap << endl;
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

    bool dfs(int v, int T, int lim) {
        if (v == T) {
            return true;
        }

        used[v] = true;

        for (size_t i = 0; i < g[v].size(); i++) {
            int idx = g[v][i];

            if (cap[idx] - flow[idx] >= lim && !used[to[idx]] && dfs(to[idx], T, lim)) {
                flow[idx] += lim;
                flow[idx ^ 1] -= lim;
                return true;
            }
        }

        return false;
    }

    int getMaxFlow(int S, int T) {
        int flow = 0;
        int addFlow = INF;

        while (addFlow > 0) {
            memset(used, false, sizeof used);
            //cout << addFlow << endl;
            if (dfs(S, T, addFlow)) {
                flow += addFlow;
            } else {
                addFlow >>= 1;
            }
        }

        return flow;
    }

};

int n, m;
char s[MAXR][MAXR];

bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

int in(int v) {
    return 2 * v;
}

int out(int v) {
    return 2 * v + 1;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int S = 2 * n * m;
    int T = 2 * n * m + 1;

    MaxFlow flow;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int ti = i + di[k];
                int tj = j + dj[k];

                if (ok(ti, tj) && s[ti][tj] != '#') {
                    flow.addEdge(out(i * m + j), in(ti * m + tj), 1);
                }
            }

            if (s[i][j] == 'B') {
                flow.addEdge(S, in(i * m + j), 2);
                flow.addEdge(in(i * m + j), out(i * m + j), 2);
            } else {
                flow.addEdge(in(i * m + j), out(i * m + j), 1);

                if (s[i][j] == 'A' || s[i][j] == 'C') {
                    flow.addEdge(out(i * m + j), T, 1);
                }
            }
        }
    }

    if (flow.getMaxFlow(S, T) == 2) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
