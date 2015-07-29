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
bool calced[1 << maxn][maxmod];
int nmod[maxmod][10];
int m, lim;
vector <int> c;

void precalc() {
    while (n) {
        c.push_back(n % 10);
        n /= 10;    
    }
    
    lim = c.size();
    for (int i = 0; i < lim; i++)
        if (c[i] != 0)
            dp[1 << i][c[i] % m] = 1;
    
    for (int mod = 0; mod < m; mod++) {
        for (int last = 0; last < 10; last++) {
            for (int nm = 0; nm < m; nm++)
                if ((nm * 10 + last) % m == mod) {
                    nmod[mod][last] = nm;
                    break;
                }
        }
    }
}

ll calc(int mask, int mod) {
    if (!(mask & (mask - 1)) || calced[mask][mod])
        return dp[mask][mod];
        
    ll& ans = dp[mask][mod];
    calced[mask][mod] = true;
    
    bool used[10];
    memset(used, false, sizeof used);
    
    for (int i = 0; i < lim; i++) {
        if ((mask & (1 << i)) && !used[c[i]]) {
            ans += calc(mask - (1 << i), nmod[mod][c[i]]);
            used[c[i]] = true;
        }
    }
    
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    cin >> n >> m;
    
    precalc();
    
    cout << calc((1 << lim) - 1, 0);
    
    return 0;
}
