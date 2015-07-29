/****************************************
**          Solution by NU #2          **
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
const int MAXN = 210;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int c[18];
int x[MAXN], y[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    return 0;
}
