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

int n, k, ans;
int a[MAXN], cnt[10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans += a[i] / 10;
        cnt[a[i] % 10]++;
    }

    for (int i = 9; i > 0; i--) {
        int c = min(cnt[i], k / (10 - i));

        ans += c;
        k -= c * (10 - i);
    }

    if (k > 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] % 10 != 0) {
                a[i] = (a[i] / 10 + 1) * 10;
            }

            int diff = min(100 - a[i], k);
            ans += diff / 10;
            k -= diff;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
