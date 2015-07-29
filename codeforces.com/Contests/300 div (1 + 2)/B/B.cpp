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
const int MAXN = 1000 * 1000 + 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> nums;
int dp[MAXN];
int par[MAXN];

bool check(int n) {
    while (n > 0) {
        if (n % 10 != 0 && n % 10 != 1) {
            return false;
        }

        n /= 10;
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        if (check(i)) {
            nums.push_back(i);
        }
    }

    memset(dp, 255, sizeof dp);
    par[0] = -1;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        par[i] = 1;
        
        for (size_t j = 0; j < nums.size(); j++) {
            int num = nums[j];

            if (i - num >= 0) {
                if (dp[i - num] < dp[i]) {
                    dp[i] = dp[i - num] + 1;
                    par[i] = num;
                }
            }
        }
    }

    printf("%d\n", dp[n]);
    
    for (int pos = n; pos != 0; pos -= par[pos]) {
        printf("%d ", par[pos]);
    }

    return 0;
}
