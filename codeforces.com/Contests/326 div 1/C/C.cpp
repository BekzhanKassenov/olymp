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
const int LG = 17;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ostream& operator << (ostream& out, const vector <int>& vec) {
    out << "{ ";

    for (auto x: vec) {
        out << x << ' ';
    }

    out << "}";

    return out;
}

int n, m, q;
vector <int> g[MAXN];
vector <int> dp[MAXN][LG];

int anc[MAXN][LG];
int tin[MAXN], tout[MAXN], timer;

void crop(vector <int>& vec, int lim) {
    while ((int)vec.size() > lim) {
        vec.pop_back();
    }
}   

void cropmerge(const vector <int>& a, const vector <int>& b, vector <int>& result) {
    result.resize(a.size() + b.size());

    merge(all(a), all(b), result.begin());
    result.resize(unique(all(result)) - result.begin());

    crop(result, 10);
}

void add(vector <int>& cur, const vector <int>& to_add) {
    static vector <int> temp;
    cropmerge(cur, to_add, temp);
    cur.swap(temp);
}

void dfs(int v, int par = 1) {
    tin[v] = timer++;

    anc[v][0] = par;
    
    sort(all(dp[v][0]));
    crop(dp[v][0], 10);

    for (int i = 1; i < LG; i++) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
        cropmerge(dp[v][i - 1], dp[anc[v][i - 1]][i - 1], dp[v][i]);
    }

    for (int to: g[v]) {
        if (to != par) {
            dfs(to, v);
        }
    }

    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (upper(a, b)) {
        return a;
    }

    if (upper(b, a)) {
        return b;
    }

    for (int i = LG - 1; i >= 0; i--) {
        if (!upper(anc[b][i], a)) {
            b = anc[b][i];
        }
    }
    
    return anc[b][0];
}

void solveOne(int a, int b, vector <int>& result) {
    assert(upper(a, b));

    result.clear();

    for (int i = LG - 1; i >= 0; i--) {
        if (!upper(anc[b][i], a)) {
            add(result, dp[b][i]);
            b = anc[b][i];
        }
    }

    add(result, dp[b][0]);
}

void query(int a, int b, vector <int>& result) {
    int l = lca(a, b);
    
    if (a == b) {
        result = dp[a][0];
        return;
    }

    if (l == b) {
        swap(a, b);
    }

    if (l == a) {
        solveOne(a, b, result);
        add(result, dp[a][0]);
        return;
    }

    result.clear();
    vector <int> temp;

    solveOne(l, a, temp);
    add(result, temp);

    solveOne(l, b, temp);
    add(result, temp);

    add(result, dp[l][0]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        dp[x][0].push_back(i);
    }

    dfs(1);

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    */
    vector <int> result;
    for (int i = 0; i < q; i++) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);

        query(u, v, result);

        crop(result, a);

        printf("%u", result.size());
        for (int x: result) {
            printf(" %d", x);
        }

        puts("");
    }

    return 0;
}
