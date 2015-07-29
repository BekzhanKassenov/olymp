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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct edge {
    int from, to;
    int get(int k) {
        if (k == from)
            return to;

        return from;
    }
};

edge e[MAXN];
int cas;
int n, m, ans;
vector <int> g[MAXN];
bool used[MAXN];
vector <int> st, pet;
int x, y;
int col[MAXN];

void dfs(int v, int gl = 0, int pare = -1) {
    used[v] = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].get(v);

        if (!used[to])
            dfs(to, gl + 1, g[v][i]);
        else if (gl > 0 && pare != g[v][i]) {
            ans = 0;
        }
    }
}

void dfs1(int v, int& cntn, int& cntm, int pare = -1) {
    st.push_back(v);
    col[v] = 1;
    cntn++;
    cntm += g[v].size();

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].get(v);

        if (col[to] == 0) {
            dfs1(to, cntn, cntm, g[v][i]);
        } else if (col[to] == 1 && g[v][i] != pare) {
            int pos = st.size() - 1;

            do {
                used[st[pos]] = true;
                pos--;
            } while (pos >= 0 && st[pos] != to);


            ans = (ans * 2ll) % MOD;
        }
    }

    st.pop_back();
    col[v] = 2;
}

int dfs2(int v) {
    used[v] = true;
    int ans = 1;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = e[g[v][i]].get(v);

        if (!used[to])
            ans += dfs2(to);
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
        
    while (scanf("%d%d", &m, &n) && (n || m)) {
        ans = 1;
        cas++;

        for (int i = 0; i < n; i++) {
            g[i].clear();
            col[i] = 0;
            used[i] = false;
        }

        pet.clear();

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &e[i].from, &e[i].to);
            g[e[i].from].push_back(i);
            
            if (e[i].from != e[i].to)
                g[e[i].to].push_back(i);
            else
                pet.push_back(e[i].to);
        }

        for (size_t i = 0; i < pet.size(); i++) {
            if (!used[pet[i]])
                dfs(pet[i]);
        }

        for (int i = 0; i < n; i++) {
            if (!used[i] && !col[i]) {
                int cntn = 0, cntm = 0;
                dfs1(i, cntn, cntm);
                
                if (cntn + cntn < cntm)
                    ans = 0;
            }
        }

        for (int i = 0; i < n; i++)
            if (!used[i])
                ans = (1ll * ans * dfs2(i)) % MOD;

        printf("Case %d: %d\n", cas, ans);
    }
    
    return 0;
}
