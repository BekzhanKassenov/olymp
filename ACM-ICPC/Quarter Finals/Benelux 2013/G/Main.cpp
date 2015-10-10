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

int T, n;
double w;
double x[MAXN], y[MAXN], r[MAXN];
vector <int> g[MAXN];
int parent[MAXN];
int size[MAXN];
double dist[MAXN][MAXN];

int getParent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = getParent(parent[v]);
}

void unite(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) {
        return;
    }

    if (size[a] > size[b]) {
        parent[b] = a;
        size[a] += size[b];
    } else {
        parent[a] = b;
        size[b] += size[a];
    }
}

bool check(double rr) {
    for (int i = 0; i <= n + 1; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (x[i] - r[i] <= 2 * rr) {
            unite(0, i);
        }

        if (w - x[i] - r[i] <= 2 * rr) {
            unite(n + 1, i);
        }

        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= sqr(r[i] + r[j] + 2 * rr)) {
                unite(i, j);
            }
        }
    }

    return getParent(0) != getParent(n + 1);
}

double solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
        }
    }

    double l = 0, r = w / 2;

    for (int iter = 0; iter < 50; iter++) {
        double mid = (l + r) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> T;

    while (T--) {
        cin >> w >> n;

        for (int i = 1; i <= n; i++)  {
            cin >> x[i] >> y[i] >> r[i];
        }

        cout << setprecision(10) << fixed;
        cout << solve() << endl;
    }
    
    return 0;
}
