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
const int MAXN = MAXR * MAXR * 4;
const int MAXE = MAXN * 10;
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

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int S = n * m;
    int T = n * m + 1;

    MaxFlow flow;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                continue;
            }

            cnt++;
            if ((i + j) & 1) {
                flow.addEdge(i * m + j, T, 1);
            } else {
                flow.addEdge(S, i * m + j, 1);

                for (int k = 0; k < 4; k++) {
                    int ti = i + di[k];
                    int tj = j + dj[k];
                    
                    if (ok(ti, tj) && s[ti][tj] != '#') {
                        flow.addEdge(i * m + j, ti * m + tj, 1);
                    }
                }
            }
        }
    }

    if (2 * flow.getMaxFlow(S, T) == cnt) {
        puts("Yes");
    } else {
        puts("No");
    }
    
    return 0;
}
