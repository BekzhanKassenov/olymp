#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10010;

int n, k, p, x;
int win[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &p);

    win[n] = false;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j <= n && j - i <= k; j++) {
            if (!win[j]) {
                win[i] = true;
            }
        }
    }

    int cur = 0;

    while (p --> 0) {
        scanf("%d", &x);

        if (win[cur] && win[cur + x]) {
            putchar('F');
        } else {
            putchar('T');
        }

        putchar('\n');
        cur += x;
    }
    
    return 0;
}
