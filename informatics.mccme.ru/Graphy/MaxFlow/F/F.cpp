#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 60 * 60;
const int MAXM = 10 * 4 * MAXN;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

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
        int lim = 8;
        int flow = 0;

        while (lim > 0) {
            if (dfs(S, T, lim)) {
                flow += lim;
            } else {
                lim >>= 1;
            }

            memset(used, false, sizeof used);
        }

        return flow;
    }

    bool check(int S, int T) {
        for (int i = 0; i < lastEdge; i += 2) {
            if (from[i] == S || to[i] == T) {
                if (flow[i] != cap[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

map <char, int> valency;
MaxFlow maxFlow;
char s[60][60];
int n, m;
bool good;

bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

int index(int i, int j) {
    return i * m + j;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    valency['H'] = 1;
    valency['O'] = 2;
    valency['N'] = 3;
    valency['C'] = 4;

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int S = n * m, T = n * m + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                continue;
            }

            good = true;

            for (int k = 0; k < 4; k++) {
                int ti = i + di[k];
                int tj = j + dj[k];

                if (ok(ti, tj) && s[ti][tj] != '.') {
                    if ((i + j) & 1) {
                        maxFlow.addEdge(index(i, j), index(ti, tj), 1);
                    }
                }
            }

            if ((i + j) & 1) {
                maxFlow.addEdge(S, index(i, j), valency[s[i][j]]);
            } else {
                maxFlow.addEdge(index(i, j), T, valency[s[i][j]]);
            }
        }
    }

    if (!good) {
        puts("Invalid");
        return 0;
    }

    maxFlow.getMaxFlow(S, T);

    if (maxFlow.check(S, T)) {
        puts("Valid");
    } else {
        puts("Invalid");
    }

    return 0;
}
