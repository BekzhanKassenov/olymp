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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, x, y, a[maxn], b[maxn];
int ans[maxn], last;
vector <int> g[maxn];
queue <int> q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!a[i])
            q.push(i);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        b[v]++;
        ans[last++] = v + 1;

        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            b[to]++;

            if (b[to] == a[to]) {
                q.push(to);
            }
        }
    }

    printf("%d\n", last);

    for (int i = 0; i < last; i++)
        printf("%d ", ans[i]);

    return 0;
}
