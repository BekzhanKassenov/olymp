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

int n, m, V;
char s[50], t[50];
bool g[500][500];

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);
    gets(s);
    gets(t);
    V = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ti = 0, tj = 0;

            if (s[i] == '>') {
                ti = i;
                tj = j + 1;
            } else {
                ti = i;
                tj = j - 1;
            }

            if (ok(ti, tj))
                g[i * m + j][ti * m + tj] = true;

            if (t[j] == '^') {
                ti = i - 1;
                tj = j;
            } else {
                ti = i + 1;
                tj = j;
            }

            if (ok(ti, tj))
                g[i * m + j][ti * m + tj] = true;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (g[i][k] && g[k][j])
                    g[i][j] = true;
            }
        }
    }

    bool flag = true;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && !g[i][j])
                flag = false;
        }
    }

    if (flag)
        puts("YES");
    else
        puts("NO");

    return 0;
}
