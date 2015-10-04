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
const double INF = 1e100;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1610;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
double vf, vr;
double x[MAXN], y[MAXN];
double g[MAXN][MAXN];
double dist[MAXN];
int par[MAXN];
bool used[MAXN];

inline double dst(int i, int j) {
    return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

double run(int S, int T, vector <int>& path) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    memset(used, false, sizeof used);
    memset(par, 255, sizeof par);

    dist[S] = 0;

    for (int i = 1; i <= n; i++) {
        int v = -1;

        for (int j = 1; j <= n; j++) {
            if (!used[j] && (v == -1 || dist[v] > dist[j])) {
                v = j;
            }
        }

        used[v] = true;
        if (dist[v] == INF || v == -1) {
            break;
        }

        for (int j = 1; j <= n; j++) {
            if (dist[j] > dist[v] + g[v][j]) {
                dist[j] = dist[v] + g[v][j];
                par[j] = v;
            }
        }
    }

    path.clear();
    for (int i = T; i != -1; i = par[i]) {
        path.push_back(i);
    }

    reverse(all(path));

    return dist[T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> m >> k >> vr >> vf;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = dst(i, j) / vf;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a][b] = g[b][a] = dst(a, b) / vr;
    }

    // Init list of nodes
    vector <int> nodes;
    nodes.push_back(1);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        nodes.push_back(x);
    }

    nodes.push_back(n);

    // =========================


    vector <int> path, temp;
    double ans = 0;

    for (size_t i = 0; i + 1 < nodes.size(); i++) {
        ans += run(nodes[i], nodes[i + 1], temp);

        for (size_t j = 0; j + 1 < temp.size(); j++) {
            path.push_back(temp[j]);
        }
    }

    path.push_back(n);

    cout << setprecision(10) << fixed;

    cout << ans << endl;

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
