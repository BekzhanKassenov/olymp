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
const int MAXN = 50;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <int> g[MAXN];
int color[MAXN];
int pos[MAXN];
int edge12[MAXN];
int edge21[MAXN];
vector <int> comp1, comp2;

void dfs(int v, vector <int> comp[2], int c) {
    color[v] = c;
    comp[c].push_back(v);

    for (int to: g[v]) {
        if (color[to] == -1) {
            dfs(to, comp, c ^ 1);
        }
    }
}

void prepare() {
    memset(color, 255, sizeof color);

    vector <int> temp[2];

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            temp[0].clear();
            temp[1].clear();

            dfs(i, temp, 0);

            if (temp[0].size() > temp[1].size()) {
                temp[0].swap(temp[1]);
            }

            for (int num: temp[0]) {
                comp1.push_back(num);
            }

            for (int num: temp[1]) {
                comp2.push_back(num);
            }
        }
    }

    for (size_t i = 0; i < comp1.size(); i++) {
        pos[comp1[i]] = i;
        color[comp1[i]] = 0;
    }

    for (size_t i = 0; i < comp2.size(); i++) {
        pos[comp2[i]] = i;
        color[comp2[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int to: g[i]) {
            if (color[i] == 0) {
                edge12[pos[i]] |= 1 << pos[to];
            } else {
                edge21[pos[to]] |= 1 << pos[i];
            }
        }
    }
}

int dp[30][1 << 16];

int getDp(int mask1, int mask2) {
    vector <int> masks;
    for (int sub = mask1; sub > 0; sub = (sub - 1) & mask1) {
        masks.push_back(sub);
    }

    masks.push_back(0);

    vector <int> poss;
    for (int i = 0; i <= 30; i++) {
        if (mask2 & (1 << i)) {
            poss.push_back(i);
        }
    }
    
    int len = poss.size();

    for (int i = 0; i <= len; i++) {
        for (int mask: masks) {
            dp[i][mask] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < len; i++) {
        for (int mask: masks) {
            dp[i + 1][mask] += dp[i][mask];
            dp[i + 1][(mask | edge21[poss[i]]) & mask1] += dp[i][mask];
        }
    }

    if (mask1 == 0 && mask2 == 3) {
        cerr << "DP" << endl;
        for (int i = 0; i <= len; i++) {
            for (int mask: masks) {
                cerr << dp[i][mask] << ' ';
            }
            cerr << endl;
        }
        cerr << endl;
    }

    return dp[len][mask1];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }


    prepare();

    int s1 = comp1.size(), s2 = comp2.size();

    int ans = 0;
    for (int mask = 0; mask < (1 << s1); mask++) {
        int comp2Good = 0;
        for (int i = 0; i < s1; i++) {
            if (mask & (1 << i)) {
                comp2Good |= edge12[i];
            }
        }

        int comp2Bad = ((1 << s2) - 1) ^ comp2Good;
        int comp1Handled = mask;

        for (int i = 0; i < s2; i++) {
            if (comp2Bad & (1 << i)) {
                comp1Handled |= edge21[i];
            }
        }

        int comp1Unhandled = ((1 << s1) - 1) ^ comp1Handled;

        ans += getDp(comp1Unhandled, comp2Good);

        cerr << comp1Unhandled << ' ' << comp2Good << endl;
        cerr << mask << ' ' << ans << endl;
    }

    printf("%d\n", ans);

    return 0;
}
