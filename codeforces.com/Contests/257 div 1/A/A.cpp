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

int n, m, k;

long long optimal(int k, int n) {
    return n / (k + 1);
}

long long solve(int n, int m, int k) {
    long long height = 0, width = 0;

    if (k > m - 1) {
        width = 1;
        height = optimal(k - m + 1, n);
    } else {
        height = n;
        width = optimal(k, m); 
    }

    return height * width;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d %d\n", &n, &m, &k);

    if (n > m)
        swap(n, m);

    if (n - 1 + m - 1 < k) {
        puts("-1");
        return 0;
    }

    printf("%I64d\n", max(solve(n, m, k), solve(m, n, k)));

    return 0;
}
