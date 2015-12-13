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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN], b[MAXN];
int c[MAXN];
int pi[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < m; j++) {
        scanf("%d", &b[j]);
    }

    if (m == 1) {
        printf("%d\n", n);
        return 0;
    }

    for (int i = 0; i < m - 1; i++) {
        c[i] = b[i + 1] - b[i];
    }

    c[m - 1] = INF;

    for (int i = 0; i < n - 1; i++) {
        c[m + i] = a[i + 1] - a[i];
    }

    pi[0] = 0;
    for (int i = 1; i < n + m - 1; i++) {
        int j = pi[i - 1];

        while (j > 0 && c[j] != c[i]) {
            j = pi[j - 1];
        }

        if (c[j] == c[i]) {
            j++;
        }

        pi[i] = j;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (pi[m + i] == m - 1) {
            ans++;
        }
    }

    printf("%d\n", ans);
                    
    return 0;
}
