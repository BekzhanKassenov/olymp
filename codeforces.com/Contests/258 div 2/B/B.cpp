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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[maxn], b[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b, b + n);

    int l = 0, r = n - 1;

    while (l < r) {
        bool flag = false;

        if (a[l] == b[l]) {
            l++;
            flag = true;
        }

        if (a[r] == b[r]) {
            r--;
            flag = true;
        }

        if (!flag)
            break;
    }

    if (l >= r) {
        printf("yes %d %d\n", 1, 1);
        return 0;
    }

    reverse(b + l, b + r + 1);

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            puts("no");
            return 0;
        }
    }

    printf("yes %d %d\n", l + 1, r + 1);

    return 0;
}
