/****************************************
**          Solution by NU #2          **
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

int n, k, sum;
int a[MAXN];
int mn = INF;
long long ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }

    for (int i = 1; i <= k; i++)
        sum += a[i];
    
    for (int i = 1; i + k - 1 <= n; i++) {
        int r = i + k - 1;

        while (r >= i && sum >= 0) {
            if (a[r] - mn <= sum) {
                ans += a[r] - mn;
                sum -= a[r] - mn;
                a[r] = mn;
            } else {
                ans += sum + 1;
                a[r] -= sum + 1;
                sum = -1;
            }

            r--;
        }

        sum -= a[i];
        sum += a[i + k];
    }

    printf("%I64d\n", ans);

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    
    return 0;
}
