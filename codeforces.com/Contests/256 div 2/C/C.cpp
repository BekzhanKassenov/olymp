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
const int maxn = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[maxn];
int ans;

ll solve(int l, int r, int lev) {
    if (r - l == 1)
        return 1;

    if (l >= r)
        return 0;

    int mn = min_element(a + l, a + r) - a;

    ll res = a[mn] - lev;

    int pos = l;

    for (int i = l; i < r; i++) {
        if (a[i] == a[mn]) {
            res += solve(pos, i, a[mn]);
            
            if (res >= (r - l))
                return r - l;
            
            pos = i + 1;
        }
    }

    res += solve(pos, r, a[mn]);

    return min(res, (ll)r - l);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
        
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    ll temp = solve(0, n, 0);

    if (temp > n)
        ans = n;
    else
        ans = temp;

    printf("%d", ans);

    return 0;
}
