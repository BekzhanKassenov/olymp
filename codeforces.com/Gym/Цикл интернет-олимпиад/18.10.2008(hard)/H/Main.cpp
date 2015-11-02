/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "ticket3"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &a[i]);
    }

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {
        sum1 += a[i];
    }

    for (int i = n; i < 2 * n; i++) {
        sum2 += a[i];
    }

    if (sum1 == sum2) {
        puts("YES");
        return 0;
    }

    sum1 = sum2 = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i & 1) {
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
    }

    if (sum1 == sum2) {
        puts("YES");
        return 0;
    }

    sum1 = sum2 = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i] & 1) {
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
    }

    if (sum1 == sum2) {
        puts("YES");
        return 0;
    }

    puts("NO");

    return 0;
}
                          