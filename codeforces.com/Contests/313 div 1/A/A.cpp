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

int f(int n) {
    int addend = 1;
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += addend;
        addend += 2;
    }

    return result;
}

int a[6];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
    }

    int side = a[0] + a[1] + a[2];

    printf("%d\n", f(side) - f(a[0]) - f(a[2]) - f(a[4]));
    
    return 0;
}
