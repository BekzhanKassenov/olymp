/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 18;
const int maxmod = 100;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

ll dp[1 << maxn][maxmod], n;
bool used[1 << maxn][maxmod][10];
int m, lim;
vector <int> c;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m;
    
    while (n) {
        c.push_back(n % 10);
        n /= 10;    
    }
    
    lim = c.size();
    
    for (int i = 0; i < lim; i++)
        if (c[i] != 0)
            dp[1 << i][c[i] % m] = 1;
    
    
    for (int mask = 1; mask < (1 << lim); mask++) {
        for (int mod = 0; mod < m; mod++) {
            if (dp[mask][mod] == 0)
                continue;
                
            for (int i = 0; i < lim; i++) {
                if (!(mask & (1 << i)) && !used[mask | (1 << i)][(mod * 10 + c[i]) % m][c[i]]) {
//                    used[mask | (1 << i)][(mod * 10 + c[i]) % m][c[i]] = true;
                    
                      dp[mask | (1 << i)][(mod * 10 + c[i]) % m] += dp[mask][mod];
                }
            }
        }
    }
    
    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    
    for (size_t i = 0; i < c.size(); i++)
        cnt[c[i]]++;
        
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= cnt[i]; j++)
            dp[(1 << lim) - 1][0] /= j;
    }
    
    cout << dp[(1 << lim) - 1][0];
    return 0;
}
