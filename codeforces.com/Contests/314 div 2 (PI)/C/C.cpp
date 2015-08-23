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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
map <long long, long long> _left, _right;
long long a[MAXN];
long long ans = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        _right[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        _right[a[i]]--;

        if (a[i] % k == 0) {
            ans += _left[a[i] / k] * _right[a[i] * k];
        }

        _left[a[i]]++;
    }

    printf("%I64d\n", ans);
    
    return 0;
}
