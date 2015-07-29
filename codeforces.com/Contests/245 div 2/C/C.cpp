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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <int> g[maxn];
int n, x, y, cur[maxn], goal[maxn];
vector <int> res;

void dfs(int v, int flag_even, int flag_odd, int level = 0, int pr = -1) {
    if (!level) {
        if ((cur[v] ^ flag_even) != goal[v]) {
            flag_even ^= 1;
            res.push_back(v);
        } 
    } else {
        if ((cur[v] ^ flag_odd) != goal[v]) {
            flag_odd ^= 1;
            res.push_back(v);
        }
    }

    for (size_t i = 0; i < g[v].size(); i++) {
        if (g[v][i] != pr) {
            dfs(g[v][i], flag_even, flag_odd, level ^ 1, v);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &x, &y);

        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &cur[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &goal[i]);

    dfs(0, 0, 0);

    printf("%u\n", res.size());

    for (size_t i = 0; i < res.size(); i++)
        printf("%d\n", res[i] + 1);

    return 0;
}
