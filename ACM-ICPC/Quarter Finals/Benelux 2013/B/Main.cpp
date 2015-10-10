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
const int MAXN = 16;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, c, m;
int b[MAXN];
double p[MAXN];
double dp[MAXN][MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &n, &c, &m);

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d%d", &b[i], &x);
            p[i] = x / 100.0;
        }

        double ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) >= c) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        sum += b[i];
                    }
                }

                if (m < sum) {
                    continue;
                }

                vector <int> a;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        a.push_back(i);
                    }
                }


                dp[0][0] = 1 - p[a[0]];
                dp[0][1] = p[a[0]];

                for (size_t i = 1; i < a.size(); i++) {
                    for (size_t j = 0; j <= i + 1; j++) {
                        dp[i][j] = (1 - p[a[i]]) * dp[i - 1][j];

                        if (j > 0)
                            dp[i][j] += p[a[i]] * dp[i - 1][j - 1];
                    }
                }

                double prob = 0;
                for (size_t i = c; i < a.size(); i++) {
                    prob += dp[a.size() - 1][i];
                }

                ans = max(ans, prob);
            }
        }
    
        cout << setprecision(16);
        cout << fixed;
        cout << ans << endl;
    }
    return 0;
}
