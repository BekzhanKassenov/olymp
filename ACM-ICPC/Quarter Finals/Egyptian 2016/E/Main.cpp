/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "jumping"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
vector <int> g[MAXN];
int dist[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            int d;
            scanf("%d", &d);

            if (i + d <= n) {
                g[i + d].push_back(i);
            }

            if (i - d >= 1) {
                g[i - d].push_back(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
        }

        queue <int> q;
        
        q.push(n);
        dist[n] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                if (dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            printf("%d\n", dist[i]);
        }
    }

    return 0;
}
