/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int el = *min_element(a, a + n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % k != el % k) {
            puts("-1");
            return 0;
        }

        ans += (a[i] - el) / k;
    }

    printf("%lld\n", ans);
    
    return 0;
}
