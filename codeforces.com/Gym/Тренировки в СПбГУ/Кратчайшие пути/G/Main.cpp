/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "distance"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = (int)1e18;
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int S, F;
vector <pair <int, int> > g[MAXN];
long long dist[MAXN];
int par[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    scanf("%d%d", &S, &F);

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        scanf("%d%d%d", &from, &to, &cost);
        g[from].emplace_back(cost, to);
        g[to].emplace_back(cost, from);
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[S] = 0;

    priority_queue <pair <long long, int>,
                    vector <pair <long long, int> >,
                    greater <pair <long long, int> > > q;

    q.emplace(0, S);

    while (!q.empty()) {
        long long d = q.top().first;
        int v = q.top().second;

        q.pop();

        if (dist[v] != d) {
            continue;
        }

        for (const auto& p: g[v]) {
            long long ndist = d + p.first;
            int to = p.second;

            if (dist[to] > ndist) {
                dist[to] = ndist;
                par[to] = v;

                q.emplace(dist[to], to);
            }
        }
    }

    if (par[F] == 0) {
        puts("-1");
        return 0;
    }

    vector <int> path;
    for (int i = F; i != 0; i = par[i]) {
        path.push_back(i);
    }

    reverse(all(path));

    printf("%I64d\n", dist[F]);
    for (int v: path) {
        printf("%d ", v);
    }

    puts("");

    return 0;
}
