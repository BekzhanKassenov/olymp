#include <iostream>
#include <cstdio>

using namespace std;

int n, k, m;
bool used[26];

int choose(int n, int k) {
    if (k < n - k) {
         k = n - k;
    }

    long long result = 1;
    for (int i = k + 1; i <= n; i++) {
        result *= i;
    }

    for (int i = 2; i <= n - k; i++) {
        result /= i;
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &m);

    return 0;
}
