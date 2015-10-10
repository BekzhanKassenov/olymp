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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n, m;
vector <int> g[MAXN];
int dist[MAXN];

int max_dist(int S) {
    queue <int> q;
    q.push(S);
    memset(dist, -1, sizeof dist);
    dist[S] = 0;
    int ans = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to: g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
                ans = max(ans, dist[to]);
            }
        }
    }
    
    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }

        printf("%d\n", n - 1);
    }
    
    return 0;
}
