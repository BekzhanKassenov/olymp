#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int a, b;
long long ans = 1;

long long C(int n, int k) {
    long long ans = 1;

    if (k > n - k) {
        k = n - k;
    }

    int j = 1;
    for (int i = n - k + 1; i <= n; i++) {
        ans *= i;

        while (j <= k && ans % j == 0) {
            ans /= j;
            j++;
        }
    }

    return ans;
}

long long power(long long base, int p) {
    long long result = 1;

    while (p > 0) {
        if (p & 1) {
            result *= base;
        }

        base *= base;
        p >>= 1;
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d:%d", &a, &b);

    if (a > 25 || b > 25) {
        if (abs(a - b) != 2) {
            puts("0");
            return 0;
        }

        ans = C(24 + 24, 24);
        ans *= power(2, min(a, b) - 24);
    } else {
        ans = C(a + b - 1, max(a, b) - 1);
    }

    printf("%I64d\n", ans);

    return 0;
}
