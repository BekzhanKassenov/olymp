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
bool used[100][2000];

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

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++)
            g[i][j - 1] = (s[j] == 'Y');
    }
}

void bfs(int v) {
    queue <PII> q;
    q.push(MP(v, vals[v]));
    used[v][vals[v]] = true;

    while (!q.empty()) {
        PII cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (g[cur.F][i] && !used[i][cur.S ^ vals[i]]) {
                used[i][cur.S ^ vals[i]] = true;
                q.push(MP(i, cur.S ^ vals[i]));
            }
        }
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    read();
    bfs(0);

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2000; j++)
            if (used[i][j])
                ans = max(ans, j);

    cout << ans;
    return 0;
}