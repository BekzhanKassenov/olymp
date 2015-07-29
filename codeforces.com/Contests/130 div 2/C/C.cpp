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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int x, y;
bool g[MAXN][MAXN];
long long ways[MAXN], ways1[MAXN];
int d[MAXN], d1[MAXN];
bool inque[MAXN];
double ans[MAXN];
queue <int> q;

void bfs(int v, long long w[], int d[]) {
    d[v] = 0;
    w[v] = 1;
    q.push(v);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (!g[v][i])
                continue;

            if (d[i] == -1 || d[i] > d[v] + 1) {
                d[i] = d[v] + 1;
                q.push(i);
                w[i] = w[v];
            } else if (d[i] == d[v] + 1)
                w[i] += w[v];
            
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE    
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d",&x, &y);
        x--, y--;
        g[x][y] = g[y][x] = true;
    }
    
    memset(d1, 255, sizeof d1);
    memset(d, 255, sizeof d);
    bfs(n - 1, ways1, d1);
    bfs(0, ways, d);
    
    assert(ways[n - 1]);
    double ans = 1;
    for (int i = 1; i < n - 1; i++)
        if (d[i] + d1[i] == d[n - 1]) {
            double num = 2.0 * ways[i] * ways1[i];
            double den = ways[n - 1];

            ans = max(ans, num / den);
        }
    
    printf("%.9lf", ans);
    return 0;
}
