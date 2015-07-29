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

int n, xs, ys, xf, yf, last;
int row, l, r, f, s;
set <pair <int, int> > cells;
vector <int> g[maxn];
map <pair <int, int>, int> number;
int dist[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &xs, &ys, &xf, &yf);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &row, &l, &r);

        for (int j = l; j <= r; j++) {
            if (cells.find(MP(row, j)) == cells.end()) {
                cells.insert(MP(row, j));
                number[MP(row, j)] = last++;
            }
        }
    }

    for (set <pair <int, int> > :: iterator it = cells.begin(); it != cells.end(); it++) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int tx = it -> F + dx;
                int ty = it -> S + dy;

                if (tx == it -> F && ty == it -> S)
                    continue;

                if (cells.find(MP(tx, ty)) != cells.end())
                    g[number[*it]].push_back(number[MP(tx, ty)]);
            }
        }

        if (it -> F == xs && it -> S == ys)
            s = number[*it];
        else if (it -> F == xf && it -> S == yf)
            f = number[*it];
    }

    memset(dist, 255, sizeof dist);
    dist[s] = 0;
    queue <int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (size_t j = 0; j < g[v].size(); j++) {
            int to = g[v][j];

            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    printf("%d\n", dist[f]);

    return 0;
}
