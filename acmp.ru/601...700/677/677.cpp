#include <iostream>
#include <cstdio>

using namespace std;

int k, n, m, d;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d%d%d", &k, &n, &m, &d);

    int num = k * m * n * d;
    int den = k * m * n - k * n - k * m - m * n;

    if (den <= 0 || num % den != 0) {
        puts("-1");
    } else {
        int x = num / den;

        if (x % k != 0 || x % n != 0 || x % m != 0) {
            puts("-1");
        } else {
            printf("%d\n", x);
        }
    }

    return 0;
}
