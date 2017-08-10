#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 200010;

int n;
char s[2 * MAXN];
int z[2 * MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);
    gets(s);

    strcpy(s + n + 1, s);
    s[n] = '#';
    reverse(s + n + 1, s + 2 * n + 1);

    for (int i = 1, l = 0, r = 0; i < 2 * n + 1; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < 2 * n + 1 && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 >= r) {
            l = i, r = i + z[i] - 1;
        }
    }

    for (int i = 2 * n; i > n; i--) {
        printf("%d ", z[i]);
    }

    return 0;
}
