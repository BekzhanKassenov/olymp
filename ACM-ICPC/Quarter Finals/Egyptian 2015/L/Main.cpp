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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, T;
int a[MAXN];
bool calced[MAXN];
bool dp[MAXN];

bool win(int x) {
    if (calced[x]) {
        return dp[x];
    }

    bool& ans = dp[x];
    calced[x] = true;

    if (x < n) {
        return ans = false;
    }

    if ((n - 1) * n >= x) {
        return ans = true;
    }

    for (int i = n; i <= x - n + 1; i++) {
        int rest = x - i;
        if (sqr(n - 1) >= rest && !win(i)) {
            return ans = true;
        }
    }

    return ans = false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int mx = *max_element(a, a + n);
        memset(calced, false, sizeof(bool) * (mx + 1));

        bool good = false;
        for (int i = 0; i < n; i++) {
            if (win(a[i])) {
               good = true;
            }
        }

        if (good) {
            puts("Alice");
        } else {
            puts("Bob");
        }
    }

    return 0;
}
