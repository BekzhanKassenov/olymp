/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define cnt first
#define len second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const ll BASE = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
string text[MAXN];
string s, t;
string words[MAXN];
map <string, int> to_int;

vector <int> g[MAXN];
vector <int> g_inv[MAXN];
vector <int> order;
vector <pair <int, int> > edge_list;
pair <int, int> val[MAXN];
bool used[MAXN];

vector <int> comp[MAXN];
vector <int> g_comp[MAXN];
int comp_num[MAXN];
int cond_size;
pair <int, int> dp[MAXN];

void set_param(const string& s, pair <int, int>& param) {
    param.len = s.size();
    param.cnt = 0;

    for (string::const_iterator it = s.begin(); it != s.end(); it++) {
        if (*it == 'r') {
            param.cnt++;
        }
    }
}

void tolower(string& s) {
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        *it = tolower(*it);
    }
}

int add(const string& s) {
    if (!to_int.count(s)) {
        words[n] = s;
        to_int[s] = n;
        set_param(s, val[n]);
        n++;

        return n - 1;
    }
    
    return to_int[s];
}

void add_edge(int a, int b) {
    edge_list.push_back(make_pair(a, b));
    g[a].push_back(b);
    g_inv[b].push_back(a);
}

void dfs(int v) {
    used[v] = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
        }
    }

    order.push_back(v);
}

void dfs_comp(int v, int compnum) {
    comp[compnum].push_back(v);
    comp_num[v] = compnum;
    used[v] = true;

    for (size_t i = 0; i < g_inv[v].size(); i++) {
        if (!used[g_inv[v][i]]) {
            dfs_comp(g_inv[v][i], compnum);
        }
    }
}

void dfs_dp(int v) {
    used[v] = true;

    for (size_t i = 0; i < g_comp[v].size(); i++) {
        int to = g_comp[v][i];
        
        if (!used[to]) {
            dfs_dp(to);
        }
        
        dp[v] = min(dp[v], dp[to]);
    }
}

pair <int, int>& operator += (pair <int, int>& a, const pair <int, int>& b) {
    a.len += b.len;
    a.cnt += b.cnt;
    
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> text[i];
        tolower(text[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        
        tolower(s);
        tolower(t);

        int snum = add(s);
        int tnum = add(t);

        add_edge(snum, tnum);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    memset(used, false, sizeof used);
    for (int i = n - 1; i >= 0; i--) {
        if (!used[order[i]]) {
            dfs_comp(order[i], cond_size);
            cond_size++;
        }
    }

    for (int i = 0; i < m; i++) {
        int from = comp_num[edge_list[i].first];
        int to = comp_num[edge_list[i].second];
        g_comp[from].push_back(to);
    }

    for (int i = 0; i < cond_size; i++) {
        dp[i] = val[comp[i][0]];

        for (size_t j = 1; j < comp[i].size(); j++) {
            dp[i] = min(dp[i], val[comp[i][j]]);
        }
    }

    memset(used, false, sizeof used);
    for (int i = 0; i < cond_size; i++) {
        if (!used[i]) {
            dfs_dp(i);
        }
    }

    long long anslen = 0, anscnt = 0;
    for (int i = 0; i < k; i++) {
        if (to_int.count(text[i])) {
            int num = to_int[text[i]];


            anslen += dp[comp_num[num]].len;
            anscnt += dp[comp_num[num]].cnt;
        } else {
            pair <int, int> temp;
            set_param(text[i], temp);

            anslen += temp.len;
            anscnt += temp.cnt;
        }
    }

    cout << anscnt << ' ' << anslen << endl;
    
    return 0;
}
