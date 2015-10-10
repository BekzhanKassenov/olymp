/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define cost first
#define to second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m, t;
int s, g, h;
int dists[MAXN], distg[MAXN], disth[MAXN];
vector <pair <int, int> > gr[MAXN];

void run(int S, int dist[]) {
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }

    dist[S] = 0;
    priority_queue <pair <int, int>,
                    vector <pair <int, int> >,
                    greater <pair <int, int> > > q;

    q.emplace(0, S);

    while (!q.empty()) {
        int d = q.top().first;
        int v = q.top().second;
        q.pop();

        if (dist[v] != d) {
            continue;
        }

        for (auto edge: gr[v]) {
            if (dist[edge.to] > dist[v] + edge.cost) {
                dist[edge.to] = dist[v] + edge.cost;
                q.emplace(dist[edge.to], edge.to);
            }
        }
    }
}

void clear() {
    for (int i = 0; i <= n; i++) {
        gr[i].clear();
    }
}   

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &n, &m, &t);
        scanf("%d%d%d", &s, &g, &h);

        clear();

        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            gr[a].emplace_back(c, b);
            gr[b].emplace_back(c, a);
        }

        run(s, dists);
        run(g, distg);
        run(h, disth);

        vector <int> ans;
        for (int i = 0; i < t; i++) {
            int x;
            scanf("%d", &x);

            if (dists[x] == dists[g] + distg[h] + disth[x] ||
                dists[x] == dists[h] + disth[g] + distg[x]) {
                ans.push_back(x);
            }
        }

        sort(all(ans));
        for (int x: ans) {
            printf("%d ", x);
        }
        puts("");
    }
    
    return 0;
}
