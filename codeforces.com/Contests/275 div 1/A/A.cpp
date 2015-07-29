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

int a[MAXN];
int n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
        a[i] = i;

    int l = 1, r = n;

    for (int i = 1; i <= k; i++) {
        if (i & 1)
            a[i] = l++;
        else
            a[i] = r--;
    }

    for (int i = k + 1; i <= n; i++) {
        if (k & 1)
            a[i] = l++;
        else
            a[i] = r--;
    }
    
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
}
