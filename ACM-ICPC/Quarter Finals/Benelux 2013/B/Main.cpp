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
double dp[1 << MAXN][MAXN];

double go(int mask, int cnt, int sum) {
    if (sum > m) {
        return 0.0;
    }

    if (cnt == c) {
        return 1.0;
    }

    double& ans = dp[mask][cnt];
    if (ans == ans) {
        return ans;
    }

    ans = 0;

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int nmask = mask | (1 << i);

            double yes = go(nmask, cnt + 1, sum + b[i]);
            double no  = go(nmask, cnt, sum + b[i]);
            
            ans = max(ans, p[i] * yes + (1 - p[i]) * no);
        }
    }

    return ans;
}

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

        for (int mask = 0; mask < (1 << n); mask++) {
            memset(dp[mask], 255, sizeof(double) * n);
        }

        cout << setprecision(10) << fixed;
        cout << go(0, 0, 0) << endl;
    }
    return 0;
}
