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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int x;
long long sum;
int n, k;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    if (k == 2) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            ans ^= x;
        }

        printf("%d\n", ans);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
    }

    long long num = n % k;

    for (int i = 0; i <= sum / k; i++) {
        long long lhs = sum - k * i;

        if (lhs % num == 0) {                                   
            long long a = (i + lhs / num) * k;
            long long b = sum + (lhs / num) * num;

            if (a == b) {
                printf("%I64d\n", (lhs / (num * num) - 1));
                return 0;
            }
        }
    }

    return 0;
}
