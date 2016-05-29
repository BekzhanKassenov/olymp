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
const int MAXN = 13;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
int a[3][MAXN];
int pos[3][MAXN];
int dp[1 << MAXN][3];
bool calced[1 << MAXN][3];

int go(int mask, int who) {
    int& ans = dp[mask][who];
    if (calced[mask][who]) {
        return ans;
    }

    calced[mask][who] = true;
    ans = -1;

    if (__builtin_popcount(mask) == n - 1) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                ans = i;
                break;
            }
        }

        return ans;
    }

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int res = go(mask | (1 << i), (who + 1) % 3);

            if (ans == -1 || pos[who][res] < pos[who][ans]) {
                ans = res;
            }
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
        scanf("%d", &n);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
                a[i][j]--;
                pos[i][a[i][j]] = j;
            }
        }

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < 3; j++) {
                calced[i][j] = false;
            }
        }

        printf("%d\n", go(0, 0) + 1);
    }
    
    return 0;
}
