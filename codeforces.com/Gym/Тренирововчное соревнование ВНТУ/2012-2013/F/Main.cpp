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
const ll INF = 2000 * 1000 * 1000 * 1ll * 1000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

const int maxn = 18;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}


int n, prev[1 << maxn][maxn];
ll dp[1 << maxn][maxn], a[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);

    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = INF;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (__builtin_popcount(mask) < 2)
                    dp[mask][i] = 0;

                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j)) && (dp[mask | (1 << j)][j] > dp[mask][i] + a[i] * a[j]
                        || (dp[mask | (1 << j)][j] == dp[mask][i] + a[i] * a[j] && a[prev[mask | (1 << j)][j]] > a[i]))) { 
                        
                        dp[mask | (1 << j)][j] = dp[mask][i] + a[i] * a[j];
                        prev[mask | (1 << j)][j] = i;
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (dp[(1 << n) - 1][i] < dp[(1 << n) - 1][ans] || (dp[(1 << n) - 1][i] == dp[(1 << n) - 1][ans] && a[i] < a[ans])) {
            ans = i;
        }
    }   

    vector <int> res;

    int mask = (1 << n) - 1;
    int last = ans;

    while (mask) {
        res.push_back(a[last]);
        int nlast = prev[mask][last];
        mask -= (1 << last);
        last = nlast;   
    }

    cout << dp[(1 << n) - 1][ans] << endl;;

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';

    return 0;
}
