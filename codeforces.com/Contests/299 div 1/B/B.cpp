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
const int MAXN = 3000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, len;
char p[MAXN], *s;
int x[MAXN], pi[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    gets(p);
    len = strlen(p);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x[i]);
        x[i]--;
    }

    p[len] = '#';
    s = p + len + 1;

    for (int i = 0; i < n; i++) {
        s[i] = ' ';
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < len && s[x[i] + j] == ' '; j++) {
            s[x[i] + j] = p[j];
        }
    }
    
    for (int i = 1; p[i]; i++) {
        int j = pi[i - 1];

        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }

        if (p[i] == p[j]) {
            j++;
        }

        pi[i] = j;
    }
    
    for (int i = 0; i < m; i++) {
        if (pi[x[i] + len + len] != len) {
            puts("0");
            return 0;
        }
    }


    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            ans = (1ll * ans * 26) % MOD;
        }
    }

    printf("%d\n", ans);

    return 0;
}
