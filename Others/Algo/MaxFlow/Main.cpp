#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 510;
const ll INF = (int)2e14;

ll f[maxn][maxn], c[maxn][maxn];
int n, m, a, b, sz;
bool used[maxn];

bool dfs(int v, int flow) {
    used[v] = true;
    
    if (v == n - 1)
        return true;
    
    for (int i = 0; i < n; i++) {
        if (!used[i] && c[v][i] - f[v][i] >= flow && dfs(i, flow)) {
            f[v][i] += flow;
            f[i][v] -= flow;
            return true;
        }
    }
    
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> sz;
        c[--a][--b] = sz;
    }
    
    ll cur_flow = INF;
    
    while (cur_flow) {
        memset(used, false, sizeof used);
        
        if (!dfs(0, cur_flow))
            cur_flow >>= 1;
    }
    
    ll ans = 0;
    
    for (int i = 0; i < n; i++)
        ans += f[0][i];
        
    cout << ans;
    
    return 0;
}
