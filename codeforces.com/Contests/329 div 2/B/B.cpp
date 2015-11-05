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

int n;
long long xl, xr;
long long k[MAXN], b[MAXN];
int yl[MAXN], yr[MAXN];

bool cmp1(int i, int j) {
    long long yi = k[i] * xl + b[i];
    long long yj = k[j] * xl + b[j];

    if (yi != yj) {
        return yi < yj;
    }

    if (k[i] != k[j]) {
        return k[i] < k[j];
    }

    return b[i] < b[j];
}

bool cmp2(int i, int j) {
    long long yi = k[i] * xr + b[i];
    long long yj = k[j] * xr + b[j];

    return yi < yj;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    scanf("%I64d%I64d", &xl, &xr);

    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d", &k[i], &b[i]);
    }

    for (int i = 0; i < n; i++) {
        yl[i] = i;
    }

    stable_sort(yl, yl + n, cmp1);

    memcpy(yr, yl, sizeof(int) * n);

    stable_sort(yr, yr + n, cmp2);

    for (int i = 0; i < n; i++) {
        if (yl[i] != yr[i]) {
            puts("Yes");
            return 0;
        }  
    }

    puts("No");

    return 0;
}
