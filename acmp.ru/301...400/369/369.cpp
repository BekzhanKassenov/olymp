#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 110;

int n, k, t;

struct triple {
    int t, p, s;

    triple() : t(0), p(0), s(0) { }
    
    bool operator < (const triple& rhs) const {
        return t < rhs.t;
    }
};

triple a[maxn];
int dp[maxn], ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &t);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].t);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].p);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].s);

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if ((dp[j] || !j) && a[i].s <= k && a[j].s <= k && abs(a[i].t - a[j].t) >= abs(a[i].s - a[j].s))
                dp[i] = max(dp[i], dp[j] + a[i].p);
        }

        ans = max(ans, dp[i]);
    }

    //for (int i = 0; i <= n; i++)
      //  printf("%d %d %d\n", a[i].t, a[i].s, a[i].p);

    printf("%d\n", ans);

    return 0;
}
