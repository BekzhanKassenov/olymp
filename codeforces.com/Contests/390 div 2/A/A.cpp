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
const int MAXN = 110;

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

    int pos = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (pos == -1 && a[i] != 0) {
            pos = i;
        }
    }

    if (sum != 0) {
        printf("YES\n1\n1 %d\n", n);
        return 0;
    }

    if (pos == -1) {
        puts("NO");
        return 0;
    }

    puts("YES");
    puts("2");
    printf("1 %d\n", pos + 1);
    printf("%d %d\n", pos + 2, n);

    return 0;
}
