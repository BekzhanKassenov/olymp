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
const vector <int> coins = {1, 2, 5, 10, 20, 50, 100};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool calced[7][300];
int dp[7][300];

int go(int pos, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0 || pos >= (int)coins.size()) {
        return 0;
    }

    if (calced[pos][n]) {
        return dp[pos][n];
    }

    calced[pos][n] = true;

    int& ans = dp[pos][n];
    for (int cnt = 0; n - cnt * coins[pos] >= 0; cnt++) {
        ans += go(pos + 1, n - cnt * coins[pos]);
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    printf("%d\n", go(0, n));
    
    return 0;
}
