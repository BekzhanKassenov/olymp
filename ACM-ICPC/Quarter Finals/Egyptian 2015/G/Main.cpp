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
const long long INF = 1e18;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Edge {
    int from, to;
    int cost, wisdom;

    int getOther(int v) {
        if (v == from) {
            return to;
        }

        return from;
    }
};

Edge e[MAXN];

int T;
int n, m;
vector <int> g[MAXN];
long long dist[MAXN], K;

void run(int W) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;
    priority_queue <pair <long long, int>,
                    vector <pair <long long, int> >,
                    greater <pair <long long, int> > > q;

    q.emplace(0, 1);
    while (!q.empty()) {
        long long d = q.top().first;
        int v = q.top().second;
        
        q.pop();

        if (dist[v] != d) {
            continue;
        }

        for (int idx: g[v]) {
            int to = e[idx].getOther(v);

            if (e[idx].wisdom <= W && dist[to] > dist[v] + e[idx].cost) {
                dist[to] = dist[v] + e[idx].cost;
                q.emplace(dist[to], to);
            }
        }
    }
}

void clear() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%I64d", &n, &m, &K);

        clear();

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d%d", &e[i].from, &e[i].to, &e[i].cost, &e[i].wisdom);

            g[e[i].from].push_back(i);
            g[e[i].to].push_back(i);
        }

        int ans = -1;
        int l = 0, r = (int)1e9;

        while (l <= r) {
            int mid = (l + r) / 2;

            run(mid);

            if (dist[n] < K) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
