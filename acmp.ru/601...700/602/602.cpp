#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 10010;

int n, l = -1, r = -1;
int a[maxn];
double res = 1e100;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    for (int cnt = 2; cnt <= n; cnt++) {
        for (int i = 0; i + cnt - 1 < n; i++) {
            if ((a[i + cnt - 1] - a[i]) / (cnt + .0) < res) {
                res = (a[i + cnt - 1] - a[i]) / (cnt + .0);
                l = i;
                r = i + cnt - 1;
            }
        }
    }

    printf("%d %d\n", a[l], a[r]);

    return 0;
}
