
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

bool has(int mask, int pos) {
    return mask & (1 << pos);
}

bool check(int mask) {
    for (int i = 0; i < n; i++) {
        if (!has(mask, i)) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (has(mask, j) && find(all(g[i]), j) != g[i].end()) {
                    ok = true;
                }
            }

            if (!ok) {
                return false;
            }
        }
    }

    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (check(mask)) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
