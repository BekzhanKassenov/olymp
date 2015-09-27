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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];
int par[MAXN];
double water[MAXN];
double cap[MAXN];
bool inque[MAXN];
int p[MAXN], a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i], &a[i]);

        cap[i] = p[i] - a[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        g[x].push_back(y);
        par[y]++;
    }

    int start, finish;
    int init;

    scanf("%d%d%d", &start, &init, &finish);

    queue <int> q;
    q.push(start);
    water[start] = init;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        double childs = g[v].size();

        double delta = max(.0, (water[v] - cap[v]) / childs);
        
        if (water[v] > cap[v]) {
            water[v] = cap[v];
        }

        for (int to: g[v]) {
            water[to] += delta;
            par[to]--;

            if (par[to] == 0) {
                q.push(to);
            }
        }
    }

    cout.precision(10);
    cout << fixed << a[finish] + water[finish] << endl;

    return 0;
}
