#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 10;
const int INF = 1 << 30;

int n;
int cnt[MAXN][MAXN];
int a[MAXN];
int ans = INF;
int ansa[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cnt[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    do {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != a[i]) {
                    sum += cnt[i][j];
                }
            }
        }

        if (sum < ans) {
            ans = sum;

            for (int i = 0; i < n; i++) {
                ansa[i] = a[i];
            }
        }
    } while (next_permutation(a, a + n));

    for (int i = 0; i < n; i++) {
        putchar(ansa[i] + 'A');
    }
    putchar('\n');

    printf("%d\n", ans);

    return 0;
}
