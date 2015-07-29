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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, ans, x, num, mx, pr = 1;
int cnt[5000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
        mx = max(mx, x);
    }

    num = n;

    for (int i = 0; i < 2014; i++) {
        if (cnt[i]) {
            //cout << i << ' ' << num << ' ' << 2 * (i - pr) * ((num + k - 1) / k - 1) + i - pr << endl;

            ans += 2 * (i - pr) * ((num + k - 1) / k - 1);
            ans += (i - pr);
            num -= cnt[i];
            pr = i;
        }
    }

    ans += mx - 1;

    printf("%d\n", ans);

    return 0;
}
