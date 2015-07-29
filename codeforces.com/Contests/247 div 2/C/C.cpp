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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, k, d;
int dp[2][110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &k, &d);

    dp[0][0] = 1;

    for (int sum = 1; sum <= n; sum++) {
        for (int num = 1; num <= k; num++) {
            if (sum >= num) {
                dp[0][sum] += dp[0][sum - num];
                dp[0][sum] %= MOD;

                dp[1][sum] += dp[num < d][sum - num];
                dp[1][sum] %= MOD;
            }
        }
    }

    printf("%d\n", dp[1][n]);
    return 0;
}
