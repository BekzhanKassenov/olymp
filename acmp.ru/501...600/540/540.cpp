#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 2010;

int n, m;
unsigned int r, a[maxn], diag_l[maxn], diag_r[maxn];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%u", &n, &m, &r);

    for (int i = 1; i <= m; i++) {
        scanf("%u", &a[i]);
        a[i] %= r;
    }

    for (int i = 1; i < n; i++) {
        for (int j = m; j > 0; j--) {
            diag_l[j] = diag_l[j - 1] + a[j];
            diag_l[j] %= r;
        }

        for (int j = 1; j <= m; j++) {
            diag_r[j] = diag_r[j + 1] + a[j];
            diag_r[j] %= r;
        }

        for (int j = 1; j <= m; j++) {
            if (i > 1) {
                a[j] += a[j];
                a[j] %= r;
            }

            a[j] += diag_l[j - 1] + diag_r[j + 1];
            a[j] %= r;
        }
    }

    for (int i = 1; i <= m; i++)
        printf("%u ", a[i]);

    return 0;
}
                     