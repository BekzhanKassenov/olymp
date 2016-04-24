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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Query {
    int type;
    int a, b, c;
};

Query q[MAXN * MAXN];
int n, m, k;
int a[MAXN][MAXN];

void shift_row(int r) {
    int temp = a[r][m - 1];
    for (int i = m - 1; i > 0; i--) {
        a[r][i] = a[r][i - 1];
    }

    a[r][0] = temp;
}

void shift_col(int c) {
    int temp = a[n - 1][c];
    for (int i = n - 1; i > 0; i--) {
        a[i][c] = a[i - 1][c];
    }

    a[0][c] = temp;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &q[i].type);
        if (q[i].type == 3) {
            scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
            q[i].a--;
            q[i].b--;
        } else {
            scanf("%d", &q[i].a);
            q[i].a--;
        }
    }

    for (int i = k - 1; i >= 0; i--) {
        switch (q[i].type) {
            case 1:
                shift_row(q[i].a);
                break;

            case 2:
                shift_col(q[i].a);
                break;

            case 3:
                a[q[i].a][q[i].b] = q[i].c;
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }

        puts("");
    }



    return 0;
}
