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

int d, n, a[maxn], b[maxn];
ll x;

ll getNextX() {
    x = (x * 37 + 10007) % MOD;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        swap(a[i], a[getNextX() % (i + 1)]);
    }

    for(int i = 0; i < n; i++) {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }

    for(int i = 0; i < n; i = i + 1) {
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
        
    scanf("%d %d %I64d\n", &n, &d, &x);

    initAB();



    return 0;
}
