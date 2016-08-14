#include <iostream>
#include <cstdio>

using namespace std;

long long n, m;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%lld%lld", &m, &n);

    long long ans = 0;
    int bit = 0;
    while ((ans | (1ll << bit)) <= n - m) {
        ans |= 1ll << bit;
        bit += 2;
    }

    printf("%lld\n", m + ans);

    return 0;
}
