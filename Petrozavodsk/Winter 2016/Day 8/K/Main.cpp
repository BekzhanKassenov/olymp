/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back


#define N 5555

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;

vector<int> g[N];
int dwn[N];
vector<int> dp[N][N][2];
int cnt[N];

vector<int> bro[N];

void dfs2(int v, int p = -1) {
    cnt[v] = 1;    
    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to == p) continue;
        dfs2(to, v);
        for(int j = 0; j < g[v].size(); ++j) {
            if(g[v][j] ==p || g[v][j] == to) continue;
            bro[to].pb(g[v][j]);
        }
        dwn[v] = max(dwn[v], dwn[to] + 1);
        cnt[v] += cnt[to];
    }
}

void dfs(int v, int p = -1) {
    vector<int> a;
    multiset<int> b;
    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to == p) continue;
        dfs(to, v);                
        a.pb(to);       
    }
    
    dp[0][v][0][0] = 0;
    
    for(int _i = 0; _i < a.size(); ++_i) {
        int i = a[_i];
        for(int j = S; j >= 0; --j) {
            for(int fuck = 0; fuck < 2; ++fuck) {
                for(int k = 0; k < cnt[i]; ++k) {
                    if(dp[_i + 1][v][j + k][fuck + k == 0] < max(dp[to][k][k != 0] + k == 0, dp[_i][v][j][fuck])) {
                        dp[_i + 1][v][j + k][fuck + k == 0] = max(dp[to][k][k != 0] + k == 0, dp[_i][v][j][fuck]);
                        if(k != 0) {
                            //sdfsdfg
                        }                                            
                    }
                }
            }
        }
    }





}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        g[l].pb(r);
        g[r].pb(l);
    }
    dfs2(0);

    
    return 0;
}
