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

int n, m;
int k, x;
bool boy[110], girl[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        boy[x] = true;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        girl[x] = true;
    }

    for (int i = 0; i <= sqr(n * m); i++) {
        if (boy[i % n] || girl[i % m]) {
            boy[i % n] = true;
            girl[i % m] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!boy[i]) {
            puts("No");
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (!girl[i]) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    
    return 0;
}
