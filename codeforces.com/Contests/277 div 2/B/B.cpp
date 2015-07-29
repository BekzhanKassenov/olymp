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

int n, m;
int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &B[i][j]);
            A[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (B[i][j] == 0) {
                for (int k = 1; k <= m; k++)
                    A[i][k] = 0;

                for (int k = 1; k <= n; k++)
                    A[k][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++)
                C[i][j] |= A[i][k];

            for (int k = 1; k <= n; k++)
                C[i][j] |= A[k][j];
            
            if (C[i][j] != B[i][j]) {
                puts("NO");
                return 0;
            }
        }
    }

    puts("YES");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", A[i][j]);

        puts("");
    }


    return 0;
}
