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
const int MAXN = 1000010;
const int LG = 21;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, K;
double k;
int x, y, cost, v, t;
vector <pair <int, int> > gr[MAXN];
vector <pair <int, int> > root;
vector <int> g[MAXN];
int anc[MAXN][LG];
int par[MAXN], depth[MAXN];
double p, to_push[MAXN];
double ans[MAXN];
double prec[MAXN];
vector <pair <double, int> > root_push[MAXN];

double binpow(double n, int st) {
    double res = 1;

    while (st) {
        if (st & 1)
            res *= n;

        n *= n;
        st >>= 1;
    }

    return res;
}

void dfs(int v, int pr, int dpth = 0) {
    depth[v] = dpth;

    anc[v][0] = pr;

    for (int i = 1; i < LG; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }

    for (size_t i = 0; i < g[v].size(); i++)
        dfs(g[v][i], v, dpth + 1);
}

int get_par(int v, int lev) {
    for (int i = LG - 1; i >= 0; i--) {
        if (depth[v] - depth[anc[v][i]] < lev) {
            lev -= depth[v] - depth[anc[v][i]];
            v = anc[v][i];
        }
    }

    return anc[v][0];
}

void dfs1(int v, int dpth = 0) {
    ans[v] = 0;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        dfs1(to, dpth + 1);
        
        if (dpth)
            ans[v] += ans[to];
    }

    if (dpth) {
        ans[v] *= k;
        ans[v] += to_push[v];
    }
}   

int main() {             
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d%d", &n, &m, &K);
    scanf("%lf", &k);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &cost);
        gr[x].push_back(make_pair(cost, y));
        gr[y].push_back(make_pair(cost, x));
    }

    prec[0] = 1.0;
    double power = 1.0;

    for (int i = 1; i < MAXN; i++) {
        power *= sqr(k);
        prec[i] = prec[i - 1] + power;
    }

    for (int i = 1; i <= n; i++)
        sort(all(gr[i]));

    for (int i = 1; i <= n; i++) {
        par[i] = gr[i][0].second;
        
        if (gr[par[i]][0].second == i) {
            root.push_back(make_pair(min(i, par[i]), max(i, par[i])));
        } else {
            g[par[i]].push_back(i);
        }
    }

    sort(all(root));
    root.resize(unique(all(root)) - root.begin()); 

    for (size_t i = 0; i < root.size(); i++) {
        dfs(root[i].first, root[i].first);
        dfs(root[i].second, root[i].second);
    }

    for (int i = 0; i < K; i++) {
        scanf("%d%lf%d", &v, &p, &t);

        int pr = get_par(v, t);
        to_push[v] += p;

        if (depth[v] - depth[pr] == t) {
            to_push[pr] -= p * binpow(k, t);
        } else {
            int diff = depth[v] - depth[pr];
            t -= diff;
            root_push[pr].push_back(make_pair(p * binpow(k, diff), t));
        }
    }

    for (size_t i = 0; i < root.size(); i++) {
        int v1 = root[i].first;
        int v2 = root[i].second;
        dfs1(v1);
        dfs1(v2);

        for (int qqq = 0; qqq < 2; qqq++) {
            for (size_t j = 0; j < root_push[v1].size(); j++) {
                p = root_push[v1][j].first;
                t = root_push[v1][j].second;

                if (t == 1)
                    ans[v1] += p;
                else if (t == 2) {
                    ans[v1] += p;
                    ans[v2] += p * k;
                } else {
                    int h = t / 2;

                    ans[v1] += prec[h] * p;
                    
                    if (t & 1)
                        ans[v2] += k * p * prec[h-1];
                    else
                        ans[v2] += k * p * prec[h];                    
                }
            }
            swap(v1, v2);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%.10lf\n", ans[i]);

    return 0;
}
