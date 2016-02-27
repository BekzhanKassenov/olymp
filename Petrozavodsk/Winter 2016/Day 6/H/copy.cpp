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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const int BSIZE = 330;
const int LG = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Query {
    char type;
    int u, v;
};

Query q[2 * MAXN];

vector <int> g1[MAXN], g2[MAXN];
int n, comps;
int color[MAXN], dist[MAXN];
int anc[LG][MAXN];
int tin[MAXN], tout[MAXN], timer;
int start, pos;
map <long long, long long> Map;
vector <int> side[MAXN];

long long merge(long long a, long long b) {
    long long result = (a << 32) ^ b;
    return result;
}

void unmerge(long long a, int& b, int& c) {
    b = a >> 32;
    c = a;
}

void build(int v, int c, int par) {
    //printf("color[%d] = %d\n", v, c);
    tin[v] = timer++;
    color[v] = c;

    anc[0][v] = par;
    for (int i = 1; i < LG; i++) {
        anc[i][v] = anc[i - 1][anc[i - 1][v]];
    }

    for (int to: g1[v]) {
        if (to != par) {
            dist[to] = dist[v] + 1;
            build(to, c, v);
        }
    }

    tout[v] = timer++;
}

set <pair <int, int> > edges;

void rebuild() {
    Map.clear();
    for (int i = 1; i <= n; i++) {
        g1[i].clear();
    }

    for (int i = 0; i <= n; i++) {
        g2[i].clear();
    }

    for (const auto& edge: edges) {
        int u = edge.first;
        int v = edge.second;

        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }

    comps = 0;
    timer = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            build(i, comps++, i);
        }
    }
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (ancestor(a, b)) {
        return a;
    }

    if (ancestor(b, a)) {
        return b;
    }

    for (int i = LG - 1; i >= 0; i--) {
        if (!ancestor(anc[i][b], a)) {
            b = anc[i][b];
        }
    }

    b = anc[0][b];

    return b;
}

int getDist(int a, int b) {
    int l = lca(a, b);

    return dist[a] + dist[b] - 2 * dist[l];
}

vector <int> path;
bool dfs(int v, int T, int par = -1) {
    if (v == T) {
        path.push_back(v);
        return true;
    }

    for (int to: g2[v]) {
        if (to != par && dfs(to, T, v)) {
            path.push_back(v);
            return true;
        }
    }

    return false;
}

bool check_edge(int a, int b, int u, int v) {
    assert(color[a] == color[b]);

    if (color[u] == color[a] && color[v] == color[b]) {
        if (getDist(a, u) + getDist(v, b) + 1 == getDist(a, b)) {
            return true;
        }

        if (getDist(a, v) + getDist(u, b) + 1 == getDist(a, b)) {
            return true;
        }
    }

    return false;
}

bool test(int a, int b) {
    path.clear();
    if (dfs(color[a], color[b])) {
        for (size_t i = 0; i + 1 < path.size(); i++) {
            int ca = path[i];
            int cb = path[i + 1];

            int aa, bb;
            long long h = merge(min(ca, cb), max(ca, cb));
            unmerge(Map[h], aa, bb);

            side[color[aa]].push_back(aa);
            side[color[bb]].push_back(bb);
        }
        /*

        for (int idx: path) {
            cerr << idx << endl;
        }
        */

        side[color[a]].push_back(a);
        side[color[b]].push_back(b);

        for (int i = start; i < pos; i++) {
            int u = q[i].u;
            int v = q[i].v;

            if (q[i].type == 'D') {
                int col = color[u];

                if (!side[col].empty() && check_edge(side[col][0], side[col][1], u, v)) {
                    for (int idx: path) {
                        side[idx].clear();
                    }

                    return false;
                }
            }
        }

        for (int idx: path) {
            side[idx].clear();
        }

        return true;
    } 

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    char c;
    int a, b;
    rebuild();
    start = 0;

    while (scanf("\n%c", &c) == 1 && c != 'E') {
        scanf("%d %d", &a, &b);

        if (c == 'T') {
            if (test(a, b)) {
                puts("YES");
            } else {
                puts("NO");
            }

            fflush(stdout);

            continue;
        }

        int ca = color[a];
        int cb = color[b];

        if (c == 'C') {
            edges.emplace(min(a, b), max(a, b));
            if (ca != cb) {
                g2[ca].push_back(cb);
                g2[cb].push_back(ca);
                Map[merge(min(ca, cb), max(ca, cb))] = merge(a, b);
            }

        } else {
            edges.erase({min(a, b), max(a, b)});

            auto iter = find(all(g2[ca]), cb);
            if (iter != g2[ca].end()) {
                g2[ca].erase(iter);
            }

            iter = find(all(g2[cb]), ca);
            if (iter != g2[cb].end()) {
                g2[cb].erase(iter);
            }
        }

        q[pos].type = c;
        q[pos].u = a;
        q[pos].v = b;
        pos++;
        
        if (pos % BSIZE == 0) {
            rebuild();
            start = pos;
        }
    }

    return 0;
}
