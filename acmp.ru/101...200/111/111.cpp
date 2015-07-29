#include <iostream>
#include <cstdio>

using namespace std;

int k;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &k);

    if (k <= 2) {
        puts("0");
        return 0;
    }

    for (int i = 3; i * i <= k; i++) {
        if (k % i == 0) {
            printf("%d\n", i - 1);
            return 0;
        }
    }

    if (k % 2 == 0 && k != 4) {
        printf("%d\n", k / 2 - 1);
        return 0;
    }

    printf("%d\n", k - 1);

    return 0;
}
