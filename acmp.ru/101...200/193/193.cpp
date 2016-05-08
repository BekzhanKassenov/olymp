#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 300;

int a[MAXN][MAXN];
int x[MAXN], y[MAXN], xx[MAXN], yy[MAXN];
int n, m, k;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= k; i++) {
        x[i] = MAXN + MAXN;
        xx[i] = -1;
    }

    for (int i = 1; i <= k; i++) {
        y[i] = MAXN + MAXN;
        yy[i] = -1;
    }
    
    int nnx = -1, nny = -1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);

            x[a[i][j]] = min(x[a[i][j]], j);
            xx[a[i][j]] = max(xx[a[i][j]], j);
            
            y[a[i][j]] = min(y[a[i][j]], i);
            yy[a[i][j]] = max(yy[a[i][j]], i);

            if (a[i][j] != 0) {
                nnx = j, nny = i;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        if (xx[i] == -1) {
            xx[i] = x[i] = nnx;
            yy[i] = y[i] = nny;
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%d %d %d %d\n", x[i], y[i], xx[i] + 1, yy[i] + 1);
    }

    return 0;
}
