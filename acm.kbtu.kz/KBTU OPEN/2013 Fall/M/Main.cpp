/******************************************
**          Solution by NU #2            **
******************************************/

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define File "professors"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

template <typename T>
inline T sqr(T x) {
    return (x * x);
}

vector <int> vals;
int n;
vector <vector <int> > g;
vector <vector <int> > d;
vector <int> used;
vector <vector <int> > dist, unused;

void read() {
    stringstream ss;
    string s;
    getline(cin, s);
    ss << s;
    int x;
    char c;

    while (ss >> x) {
        vals.push_back(x);
        ss >> c;
    }

    n = vals.size();

    g.resize(n, vector <int> (n));
    used.resize(n);
    dist.resize(n, vector <int> (n));

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 1; j <= n; j++)
            g[i][j - 1] = (s[j] == 'Y');
    }
}

/*void floyd(int v) {
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++) {
                if (d[i][k] == -1 || d[k][j] == -1 || d[i][j] == -1)
                    continue;

                if (d[i][j] == -1 || d[i][j] < d[i][k] ^ d[k][j])
                    cout << d[i][j] << " " << d[i][k] << " " << d[k][j] << endl, d[i][j] = d[i][k] ^ d[k][j];
            }
    }
}*/

int ans = 0;

void dfs(int v, int P, int par = -1) {
    ans = max(ans, P);
    dist[v][used[v]] = ans;
    used[v]++;

    cout << v << endl;
    for (int i = 0; i < n; i++) {
        if (g[v][i] && used[i] < n && i != par)
            dfs(i, ans ^ vals[i], v);
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    read();

    dfs(0, vals[0]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dist[i][j]);

    cout << ans;
    return 0;
}