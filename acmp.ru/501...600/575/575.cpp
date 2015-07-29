#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 110;

int n, m, a[maxn][maxn];
double ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (i < n - 1 && a[i][j] != a[i + 1][j])
                ans += 0.8;

            if (j < m - 1 && a[i][j] != a[i][j + 1])
                ans += 0.8;

            int cnt = 0;

            if (i == n - 1 || j == m - 1) {
                cnt = 3;
            } else {
                cnt = (a[i][j] == a[i + 1][j]) +
                      (a[i][j] == a[i][j + 1]) +
                      (a[i][j] == a[i + 1][j + 1]);
            }

            if (cnt != 3)
                ans += 0.2;

            //cout << i + 1 << ' ' << j + 1 << ' ' << cnt << ' ' << ans << endl; 
        }
    }

    printf("%.3lf", ans * 3.0 / 5.0);

    return 0;
}
