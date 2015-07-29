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

bool lucky(int n) {
    if (n < 0) {
         n *= -1;
    }
    
    while (n > 0) {
        if (n % 10 == 8) {
            return true;
        }

        n /= 10;
    }

    return false;
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; ;i++) {
        if (lucky(n + i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    return 0;
}
