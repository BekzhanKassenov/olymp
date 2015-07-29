#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    if (n == 1) {
        puts("45");
    } else if (n == 2) {
        puts("4905");
    } else {
        printf("494");

        for (int i = 0; i < n - 3; i++)
            printf("9");

        printf("55");

        for (int i = 0; i < n - 2; i++)
            printf("0");

        puts("");
    }

    return 0;
}
