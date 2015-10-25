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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];

int solve(int l, int r) {
    if (r - l <= 1) {
        return 0;
    }

    if (a[l] == a[r]) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (a[i] != a[l]) {
                ans++;
                a[i] = a[l];
            }
        }

        return ans;
    }

    int pos = l + 1;
    int ans = 0;
    for (int i = l + 2; i <= r; i += 2) {
        swap(a[i], a[pos]);
        pos++;
        ans++;
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int l = 1, r = 1;

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            r++;
        } else {
            ans = max(ans, solve(l, r));
            l = r = i;
        }
    }

    ans = max(ans, solve(l, r));

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    puts("");

    return 0;
}
