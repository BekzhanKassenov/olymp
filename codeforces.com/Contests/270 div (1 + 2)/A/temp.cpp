#include <iostream>
#include <cstdio>

using namespace std;

bool prime(int n) {
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int n;
    while (cin >> n) {
        int m = 8;
        n -= 8;

        if (prime(n))
            printf("%d %d\n", n - 1, m + 1);
        else
            printf("%d %d\n", n, m);
    }

    return 0;
}
