/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "commuting"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x;
int f[MAXN], g[MAXN];
int elem[MAXN]; // elem[i] is min element of all cycles of length i
bool used[MAXN];

void dfs(int v, int& len, int& minelem) {
    if (used[v]) {
        return;
    }

    used[v] = true;

    len++;
    minelem = min(minelem, f[v]);

    dfs(f[v], len, minelem);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int len = 0, minelem = INF;
            dfs(i, len, minelem);

            if (elem[len] == 0 || elem[len] > minelem) {
                elem[len] = minelem;
            }
        }
    }

    memset(used, false, sizeof used);

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int a = i;
            int len = 0, minelem = INF;

            dfs(i, len, minelem);

            int b = minelem;

            for (int k = 1; k * k <= len; k++) {
                if (len % k == 0) {
                    if (elem[k] != 0) {
                        b = min(b, elem[k]);
                    }

                    if (elem[len / k] != 0) {
                        b = min(b, elem[len / k]);
                    }
                }
            }

            while (g[a] == 0) {
                g[a] = b;
                a = f[a];
                b = f[b];
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        printf("%d ", g[i]);
    }

    puts("");

    return 0;
}
