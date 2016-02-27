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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <pair <int, char> > g[MAXN];
char s[2][MAXN];
int dp[2][MAXN];
int start[2][MAXN];
int parent[MAXN];

void dfs(int v, int idx, int par = 0, char pchar = 0) {
    parent[v] = par;

    if (pchar == s[idx][0]) {
        dp[idx][v] = 1;
        start[idx][v] = v;
    }

    for (const auto& edge: g[v]) {
        int to = edge.first;
        char c = edge.second;

        if (to == par) {
            continue;
        }

        dfs(to, idx, v, c);

        int ndp = dp[idx][to];
        if (pchar == s[idx][dp[idx][to]]) {
            ndp++;
        }

        if (ndp > dp[idx][v]) {
            dp[idx][v] = ndp;
            start[idx][v] = start[idx][to];
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        scanf("%d %d %c\n", &u, &v, &c);
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    gets(s[0]);
    memcpy(s[1], s[0], m * sizeof(char));
    reverse(s[1], s[1] + m);

    dfs(1, 0);
    dfs(1, 1);

    for (int i = 1; i <= n; i++) {
        vector <int> dp1, dp2;
        for (const auto& edge: g[i]) {
            if (edge.first != parent[i]) {
                dp1.push_back(edge.first);
                dp2.push_back(edge.first);
            }
        }

        if (dp[0][i] >= m) {
            printf("%d %d\n", start[0][i], i);
            return 0;
        }

        if (dp[1][i] >= m) {
            printf("%d %d\n", i, start[1][i]);
            return 0;
        }

        sort(all(dp1), [](int a, int b) {
            return dp[0][a] > dp[0][b];
        });

        sort(all(dp2), [](int a, int b) {
            return dp[1][a] > dp[1][b];
        });

        for (size_t j = 0; j < min((size_t)2, dp1.size()); j++) {
            for (size_t k = 0; k < min((size_t)2, dp2.size()); k++) {
                if (dp1[j] != dp2[k]) {
                    if (dp[0][dp1[j]] + dp[1][dp2[k]] >= m) {
                        printf("%d %d\n", start[0][dp1[j]], start[1][dp2[k]]);
                        return 0;
                    }
                }
            }
        }
    }

    puts("-1 -1");
    
    return 0;
}
