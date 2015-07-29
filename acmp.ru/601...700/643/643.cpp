#include <iostream>
#include <cstdio>

using namespace std;

int bits(int n) {
    int res = 0;

    while (n) {
        res += (n & 1);
        n >>= 1;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    n += bits(n);

    printf("%d\n", n);

    return 0;
}
