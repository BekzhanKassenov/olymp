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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN], b[MAXN], c[MAXN], x;

int get_diff(int a[], int b[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return a[i];
        }
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &c[i]);
    }

    sort(a, a + n);
    sort(b, b + n - 1);
    sort(c, c + n - 2);

    printf("%d\n%d\n", get_diff(a, b), get_diff(b, c));

    return 0;
}
