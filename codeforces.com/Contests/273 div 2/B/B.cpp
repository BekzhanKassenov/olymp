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

long long get_pairs(int n) {
    return n * 1ll * (n - 1) / 2; 
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);
    
    long long kmax = get_pairs(n - (m - 1));
    long long kmin = (n % m) * 1ll * get_pairs(n / m + 1) + (m - n % m) * 1ll * get_pairs(n / m);

    printf("%I64d %I64d\n", kmin, kmax);

    return 0;
}
