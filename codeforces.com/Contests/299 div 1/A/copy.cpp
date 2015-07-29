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

long long A, B;
long long l, t, m;
int n;

long long f(long long k) {
    return k * (A + B * (l - 2)) + B * m * k * (k + 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%I64d%I64d%d", &A, &B, &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d%I64d", &l, &t, &m);

        if (A + (l - 1) * B > t) {
            puts("-1");
            continue;
        }

        long long left = l, right = 200010;
        long long pos = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (f(mid) <= t) {
                left = mid + 1;
                pos = mid;
            } else {
                right = mid - 1;
            }
        }

        t -= f(pos);
        l += pos * (m - 1);
        long long delta = (t - A) / B;

        if (delta >= 0) {
            delta++;
            l += delta;
        }

        printf("%I64d\n", l);
    }
    
    return 0;
}
