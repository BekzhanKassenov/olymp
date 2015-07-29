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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[MAXN], n;
int cnt[MAXN], l[MAXN], r[MAXN];
int num;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;

        if (cnt[a[i]] == 1) {
            l[a[i]] = i;
        }

        if (cnt[a[i]] > cnt[num]) {
            num = a[i];
        }

        r[a[i]] = i;
    }

    for (int i = 0; i < MAXN; i++) {
        if (cnt[a[i]] == cnt[num] && (r[a[i]] - l[a[i]] < r[num] - l[num])) {
            num = a[i];
        }
    }

    printf("%d %d\n", l[num], r[num]);

    return 0;
}
