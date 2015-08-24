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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m, x, y;
vector <int> g[MAXN];
char s[MAXN];
bool used[MAXN];

void dfs(int v, vector <int>& comp) {
    comp.push_back(v);
    used[v] = true;

    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to, comp);
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        scanf("%d %d\n", &n, &m);

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        memset(used, false, sizeof(int) * (n + 1));
        
        gets(s + 1);

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x); 
        }

        for (int l = 1, r = n; l < r; l++, r--) {
            g[l].push_back(r);
            g[r].push_back(l);
        }

        vector <int> comp;
        int result = 1;

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i, comp);

                set <char> Set;
                bool quest = false;

                for (int idx: comp) {
                    if (s[idx] != '?') {
                        Set.insert(s[idx]);
                    } else {
                        quest = true;
                    }
                }

                if (Set.size() > 1u) {
                    result = 0;
                } else if (quest && Set.empty()) {
                    result = (result * 26ll) % MOD;
                }

                comp.clear();
            }
        }

        printf("%d\n", result);
    }
    
    return 0;
}
