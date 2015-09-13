/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "immediate"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000;
const int MAXN = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int g[MAXN][MAXN];
int parg[MAXN][MAXN];
int x, y, c;
int dp[1 << MAXN][MAXN];
int par[1 << MAXN][MAXN];

void path(int from, int to, vector <int>& vec) {
    if (parg[from][to] != -1) {
        path(from, parg[from][to], vec);
        vec.pop_back();
        path(parg[from][to], to, vec);
    } else if (from == to) {
        vec.push_back(from);
    } else {
        vec.push_back(from);
        vec.push_back(to);
    }

    //cerr << from << ' ' << to << endl;
}

void restore(int mask, int i, vector <int>& vec) {
    int j = par[mask][i];
//    cerr << mask << ' ' << i << endl;
    if (j == -1) {
        path(0, i, vec);
        return;
    }

    restore(mask ^ (1 << i), j, vec);
    if (!vec.empty()) {
        vec.pop_back();
    }
    path(j, i, vec);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);

    if (n == 1) {
        puts("0");
        puts("0 1");
        puts("0 1");
        return 0;
    }

    int fullMask = (1 << n) - 1;
    memset(dp, -1, sizeof dp);
    memset(par, -1, sizeof par);
    memset(parg, -1, sizeof parg);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = INF;
        }

        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        x--, y--;
        g[x][y] = c;
        g[y][x] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] != INF && g[k][j] != INF && i != j) {
                    if (g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                        parg[i][j] = k;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = g[0][i];
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }

            int prmask = mask ^ (1 << i);

            for (int j = 0; j < n; j++) {
                
                if ((prmask & (1 << j)) && dp[prmask][j] != -1) {
                    int ndist = dp[prmask][j] + g[j][i];

                    if (dp[mask][i] == -1 || dp[mask][i] > ndist) {
                        dp[mask][i] = ndist;
                        par[mask][i] = j;
                    }
                }
            }
        }
    }

    int ansmask = -1, ansi = -1, ansj = -1;
    int ans = -1;
    for (int mask1 = 0; mask1 < (1 << n); mask1++) {
        int mask2 = fullMask ^ mask1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[mask1][i] != -1 && dp[mask2][j] != -1) {
                    if (ans == -1 || ans > max(dp[mask1][i], dp[mask2][j])) {
                        ans = max(dp[mask1][i], dp[mask2][j]);
                        ansmask = mask1;
                        ansi = i;
                        ansj = j;
                    }
                }
            }
        }
    }

    assert(ans != -1 && ansmask != -1 && ansi != -1 && ansj != -1);

    //cerr << ansmask << ' ' << (fullMask ^ ansmask) << ' ' << ansi << ' ' << ansj << endl;

    vector <int> vec1, vec2;
    
    restore(ansmask, ansi, vec1);
    //cerr << endl;
    restore(fullMask ^ ansmask, ansj, vec2);
    
    printf("%d\n", ans);

    printf("%u", vec1.size() - 1);
    for (int x: vec1) {
        printf(" %d", x + 1);
    }
    puts("");

    printf("%u", vec2.size() - 1);
    for (int x: vec2) {
        printf(" %d", x + 1);
    }

    puts("");

    return 0;
}
