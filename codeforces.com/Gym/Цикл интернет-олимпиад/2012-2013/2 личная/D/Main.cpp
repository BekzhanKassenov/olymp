/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/
 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
 
using namespace std;
 
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "death"
 
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1010;
 
template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct Edge {
    int from, to;
    int o1, o2;

    Edge() {}

    Edge(int from, int to, int o1, int o2) : from(from), to(to), o1(o1), o2(o2) {}
};
 
int a[maxn][maxn], n, m;
int comp[maxn][maxn];
int compsize[maxn * maxn];          
bool used1[maxn * maxn];
int compowner[maxn * maxn];
vector <int> g[maxn * maxn];
vector <Edge> edges;
 
int di[4] = {1, 0, 0, -1};
int dj[4] = {0, 1, -1, 0};
 
bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
Edge edge(int from, int to, int o1, int o2) {
    return Edge(min(from, to), max(from, to), min(o1, o2), max(o1, o2));
}

int other(const pair <int, int>& e, int a) {
    if (e.first == a) {
        return e.second;
    }
    return e.first;
}
 
void dfs(int i, int j, int compnum) {
    comp[i][j] = compnum;
    compsize[compnum]++;
    for (int k = 0; k < 4; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];
        if (!ok(ti, tj)) {
            continue;
        }
        int tcomp = comp[ti][tj];
        if (tcomp == 0 && a[ti][tj] == a[i][j]) {
            dfs(ti, tj, compnum);
        }
        if (a[ti][tj] != a[i][j] && tcomp != 0) {
            edges.emplace_back(edge(compnum, tcomp, compowner[compnum], compowner[tcomp]));
        }
    }
}
 
int dfs1(int v) {
    used1[v] = true;
    int ans = compsize[v];
    for (int to : g[v]) {
        if (!used1[to]) {
            ans += dfs1(to);
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
 
    int compnum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (comp[i][j] == 0) {
                compnum++;
                compowner[compnum] = a[i][j];
                dfs(i, j, compnum);
            }
        }
    }
  
    if (compnum == 1) {
        cout << n * m << endl;
        cout << a[0][0] << ' ' << a[0][0] << endl;
        return 0;
    }
 
    sort(all(edges), [](const Edge& e1, const Edge& e2) {
        if (e1.from != e2.from) {
            return e1.from < e2.from;
        }
        return e1.to < e2.to;
    });
    edges.resize(unique(all(edges), [](const Edge& e1, const Edge& e2) {
        return e1.from == e2.from && e1.to == e2.to;
    }) - edges.begin());
    sort(all(edges), [](const Edge& e1, const Edge& e2) {
        if (e1.o1 != e2.o1) {
            return e1.o1 < e2.o1;
        }
        return e1.o2 < e2.o2;
    });

    int ans = 0;
    int owner1 = -1, owner2 = -1;

    size_t i = 0;
    while (i < edges.size()) {
        size_t j = i;
        while (j < edges.size() && edges[j].o1 == edges[i].o1 && edges[j].o2 == edges[i].o2) {
            j++;
        }

        for (size_t k = i; k < j; k++) {
            g[edges[k].from].push_back(edges[k].to);
            g[edges[k].to].push_back(edges[k].from);
        }
        auto relax = [&](int v, int k) {
            int ppl = dfs1(v);
            if (ppl > ans) {
                ans = ppl;
                owner1 = edges[k].o1;
                owner2 = edges[k].o2;
            }
        };
        for (size_t k = i; k < j; k++) {
            if (!used1[edges[k].from]) {
                relax(edges[k].from, k);
            }
            if (!used1[edges[k].to]) {
                relax(edges[k].to, k);
            }
        }
        for (size_t k = i; k < j; k++) {
            g[edges[k].from].clear();
            g[edges[k].to].clear();
            used1[edges[k].from] = false;
            used1[edges[k].to] = false;
        }
        i = j;
    }
    
    cout << ans << endl;
    cout << owner1 << ' ' << owner2 << endl;
    
    return 0;
}
