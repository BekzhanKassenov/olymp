#include <iostream>
#include <cstdio>

using namespace std;

int n, k;

int fact(int n) {
    if (n == 0)
        return 1;

    return fact(n - 1) * n;
}

int sqr(int n) {
    return n * n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    if (n < k)
        puts("0");
    else 
        printf("%d", sqr(fact(n)) / (sqr(fact(n - k)) * fact(k)));

    return 0;
}
