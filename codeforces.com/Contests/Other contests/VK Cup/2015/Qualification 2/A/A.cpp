/****************************************
**      Solution by NU: Black Kex      **
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

char s[MAXN][MAXN];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &m, &n);
    
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            putchar(s[i][j]);
            putchar(s[i][j]);
        }

        putchar('\n');

        for (int i = 0; i < n; i++) {
            putchar(s[i][j]);
            putchar(s[i][j]);
        }

        putchar('\n');
    }

    return 0;
}
