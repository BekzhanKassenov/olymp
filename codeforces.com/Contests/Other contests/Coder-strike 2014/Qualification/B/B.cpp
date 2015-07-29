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
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

bool cernel_locked[maxn], cache_locked[maxn];
int cache_queries[maxn], n, m, k, x[maxn][maxn], ans[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        memset(cache_queries, 0, sizeof cache_queries);

        for (int i = 0; i < n; i++) {
            if (cernel_locked[i] || x[i][j] == 0)
                continue;

            if (cache_locked[x[i][j]]) {
                cernel_locked[i] = true;
                ans[i] = j + 1;
            } else
                cache_queries[x[i][j]]++;
        }

        for (int i = 0; i < n; i++) {
            if (cernel_locked[i] || x[i][j] == 0)
                continue;

            if (cache_queries[x[i][j]] > 1) {
                ans[i] = j + 1;
                cernel_locked[i] = true;
                cache_locked[x[i][j]] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;

    return 0;
}
