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
const int INF = 1000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
long long a[MAXN];
long long sum;
long long ans = 1ll * INF * INF;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    if (n == 1) {
        puts("0");
        return 0;
    }

    if (n == 2) {
        for (int j = k / 2 - 1000000; j <= k / 2 + 1000000; j++) {
            ans = min(ans, abs(a[1] + j - (a[0] + (k - j))));
        }

        printf("%I64d\n", min(ans, min(abs(a[1] + k - a[0]), abs(a[1] - (a[0] + k)))) );
        return 0;
    }

    for (int i = 1; i < n; i++) {
        sum += a[i] - a[i - 1];
    }

    if (sum > 0) {
        sum = max(0LL, sum - k);
    } else if (sum < 0) {
        sum = min(0LL, sum + k);
    }

    printf("%I64d\n", abs(sum));
    
    return 0;
}                   
