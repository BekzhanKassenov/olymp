#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    if (n % 3 == 0) {
        printf("3 %d\n", n / 3);
    } else if (n % 3 == 1) {
        if (n != 4) {
            printf("2 2 3 %d\n", (n - 4) / 3);
        } else {
            puts("2 2");
            return 0;
        }
    } else {
        if (n != 2) {
            printf("2 1 3 %d\n", (n - 2) / 3);
        } else {
            puts("2 1");
            return 0;
        }
    }

    return 0;
}
