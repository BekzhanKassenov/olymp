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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x, y;
vector <int> g[MAXN];
int degree[MAXN];
char color[MAXN];

void bfs() {
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            q.push(i);
            color[i] = 'Z';
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!color[to] || color[to] == color[v]) {
                q.push(to);
                color[to] = color[v] - 1;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    bfs();


    for (int i = 1; i <= n; i++)
        printf("%c ", color[i]);

    return 0;
}
