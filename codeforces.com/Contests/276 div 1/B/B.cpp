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

int n, ans;
int a[MAXN];
bool used[1000010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    sort(a, a + n);
    int MAXX = a[n - 1];

    for (int i = 0; i < n; i++) {
        if (used[a[i]])
            continue;

        used[a[i]] = true;

        for (int j = a[i]; j <= MAXX; j += a[i]) {
            int pos = lower_bound(a, a + n, j + a[i]) - a - 1;
            if (pos < 0)
                continue;

            ans = max(ans, a[pos] % a[i]);
        } 
    }

    printf("%d", ans);

    return 0;
}
