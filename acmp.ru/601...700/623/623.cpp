#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    if (n <= 1)
        puts("1");
    else {
        int f1 = 1, f2 = 1, f3;

        for (int i = 2; i <= n; i++) {
            f3 = (f2 + f1) % 10;
            f1 = f2;
            f2 = f3;
        }

        printf("%d\n", f3);
    }

    return 0;
}
