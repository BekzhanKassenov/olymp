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

int n, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int len = 1; len < 11; len++) {
        for (int mask = 0; mask < (1 << len); mask++) {
            long long num = 0;

            for (int i = 0; i < len; i++) {
                num *= 10;
                
                if (mask & (1 << i)) {
                    num += 7;
                } else {
                    num += 4;
                }
            }

            if (num < n) {
                ans++;
            }
        }
    }

    printf("%d\n", ans + 1);
    
    return 0;
}
