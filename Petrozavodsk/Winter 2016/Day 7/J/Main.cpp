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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int p[4];
int a[MAXN];
long long dp[4][MAXN];


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 0; i < 4; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;

        for (int j = 0; j < i; j++) {
            for (int k = 1; k < 4; k++) {
                if ((a[i] - a[j]) * (p[k] - p[k - 1]) >= 0) {
                    dp[k][i] += dp[k - 1][j];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[3][i];
    }

    printf("%I64d\n", ans);
    
    return 0;
}
