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

int n, k;
int a[MAXN], b[MAXN];

bool check(int cnt, int k) {
    for (int i = 0; i < n; i++) {
        long long need = a[i] * 1ll * cnt;
        if (need > b[i] + k) {
            return false;
        }

        if (need > b[i]) {
            k -= need - b[i];
        }
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int ans = 0;
    int l = 0, r = 2e9 + 10;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, k)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
