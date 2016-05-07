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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
int cnt[MAXN];
int ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = i; j <= n; j++) {
            cnt[a[j]]++;
            if (cnt[a[j]] > cnt[a[mx]] || (cnt[a[j]] == cnt[a[mx]] && a[j] < a[mx])) {
                mx = j;
            }

            ans[a[mx]]++;
        }

        memset(cnt, 0, sizeof(int) * (n + 2));
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    puts("");

    return 0;
}
