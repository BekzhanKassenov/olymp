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

int n;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum % 2 == 1) {
        puts("NO");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            if (i < n && a[i + 1] > 0) {
                a[i + 1]--;
                a[i]--;
            } else {
                puts("NO");
                return 0;
            }
        }
    }

    puts("YES");
    return 0;
}
