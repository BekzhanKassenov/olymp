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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int t, a, b;
vector <int> g[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
            g[i].clear();

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
        }


    }

    return 0;
}
