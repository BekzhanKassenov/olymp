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
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n1, n2, k1, k2;
bool calced[MAXN][MAXN][2];
bool dp[MAXN][MAXN][2];

bool win(int a, int b, int who) {
    if (calced[a][b][who]) {
        return dp[a][b][who];
    }

    calced[a][b][who] = true;
    if (who == 0) {
        for (int i = 1; i <= min(k1, a); i++) {
            if (!win(a - i, b, who ^ 1)) {
                dp[a][b][who] = true;
                return true;
            }
        }

        dp[a][b][who] = false;
        return false;
    } else {
        for (int i = 1; i <= min(k2, b); i++) {
            if (!win(a, b - i, who ^ 1)) {
                dp[a][b][who] = true;
                return true;
            }
        }

        dp[a][b][who] = false;
        return false;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);

    if (win(n1, n2, 0)) {
        puts("First");
    } else {
        puts("Second");
    }
    
    return 0;
}
