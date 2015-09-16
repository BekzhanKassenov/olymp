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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 210;
const int MAXM = 2 * MAXN * MAXN;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const int S = MAXN - 2;
const int T = MAXN - 1;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct MaxFlow {
    int to[MAXM];
    int flow[MAXM], cap[MAXM];
    int lastEdge;

    vector <int> g[MAXN];

    bool used[MAXN];

    MaxFlow() : lastEdge(0) { }

    void addEdge(int from, int to, int cap) {
        this->to[lastEdge] = to;
        this->flow[lastEdge] = 0;
        this->cap[lastEdge] = cap;
        g[from].push_back(lastEdge++);

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
        int curFlow = 1 << 30;
        int resFlow = 0;

        while (curFlow > 0) {
            if (dfs(S, T, curFlow)) {
                resFlow += curFlow;
            } else {
                curFlow >>= 1;
            }

            memset(used, false, sizeof used);
        }

        return resFlow;
    }
};

MaxFlow maxFlow;

int n, t;
char a[15][15];
char b[15][15];
int dist[15][15];
bool used[15][15];

bool ok(int x, int y) {
    return 0 <= x && x < n &&
           0 <= y && y < n &&
           a[x][y] != 'Y' &&
           a[x][y] != 'Z';
}

void bfsDeath(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }

    queue <int> X, Y;
    dist[x][y] = 0;
    X.push(x);
    Y.push(y);

    while (!X.empty()) {
        assert(!Y.empty());

        int curx = X.front();
        int cury = Y.front();

        X.pop();
        Y.pop();

        for (int k = 0; k < 4; k++) {
            int tx = curx + dx[k];
            int ty = cury + dy[k];

            if (ok(tx, ty) && dist[tx][ty] == INF) {
                dist[tx][ty] = dist[curx][cury] + 1;
                X.push(tx);
                Y.push(ty);
            }
        }
    }
}

void runBFS(int x, int y) {
    queue <int> X, Y, lev;
    memset(used, false, sizeof used);
    
    used[x][y] = true;
    X.push(x);
    Y.push(y);
    lev.push(0);

    while (!X.empty()) {
        assert(!Y.empty());

        int curx = X.front();
        int cury = Y.front();
        int curlev = lev.front();

        X.pop();
        Y.pop();
        lev.pop();

        if (isdigit(b[curx][cury]) && b[curx][cury] != '0') {
            maxFlow.addEdge(x * n + y, sqr(n) + 1 + curx * n + cury, INF);
        }
        
        if (curlev >= t) {
            continue;
        }

        for (int k = 0; k < 4; k++) {
            int tx = curx + dx[k];
            int ty = cury + dy[k];

            if (ok(tx, ty) && !used[tx][ty]) {
                if (dist[tx][ty] > curlev + 1) {
                    X.push(tx);
                    Y.push(ty);

                    lev.push(curlev + 1);
                } else if (dist[tx][ty] > curlev && isdigit(b[tx][ty]) && b[tx][ty] != '0') {
                    maxFlow.addEdge(x * n + y, sqr(n) + 1 + tx * n + ty, INF);
//                    printf("(%d, %d) --> (%d, %d)\n", x, y, tx, ty);
                }

                used[tx][ty] = true;
            }
        }
    }
}

void build() {

    int posi = -1, posj = -1;
    for (int i = 0; i < n && posi == -1; i++) {
        for (int j = 0; j < n && posi == -1; j++) {
            if (a[i][j] == 'Z') {
                posi = i, posj = j;
            }
        }
    }

    bfsDeath(posi, posj);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isdigit(a[i][j]) && a[i][j] != '0') {
                maxFlow.addEdge(S, i * n + j, a[i][j] - '0');
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isdigit(b[i][j]) && b[i][j] != '0') {
                maxFlow.addEdge(i * n + j + sqr(n) + 1, T, b[i][j] - '0');
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isdigit(a[i][j]) && a[i][j] != '0') {
                runBFS(i, j);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d", &n, &t);

    scanf("\n");
    for (int i = 0; i < n; i++) {
        gets(a[i]);
    }

    scanf("\n");
    for (int i = 0; i < n; i++) {
        gets(b[i]);
    }

    build();

    printf("%d\n", maxFlow.getMaxFlow(S, T));

    return 0;
}
