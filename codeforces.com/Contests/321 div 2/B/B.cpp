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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, d;
pair <int, int> a[MAXN];
long long sum, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &d);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    sort(a, a + n);

    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && a[r].first - a[l].first < d) {
            sum += a[r].second;
            r++;
        }

        ans = max(ans, sum);

        sum -= a[l].second;
    }

    printf("%I64d\n", ans);

    return 0;
}
