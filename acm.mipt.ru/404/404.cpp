#include <iostream>
#include <cstdio>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif

int n, k;
int power[1030];

void factorize(int num, int delta) {
    for (int i = 2; num > 1; i++) {
        while (num % i == 0) {
            power[i] += delta;
            num /= i;
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 2; i <= n; i++) {
        factorize(i, 1);
    }

    for (int i = 2; i <= k; i++) {
        factorize(i, -1);
    }

    for (int i = 2; i <= n - k; i++) {
        factorize(i, -1);
    }

    long long ans = 1;
    for (int i = 1; i < 1030; i++) {
        for (int j = 0; j < power[i]; j++) {
            ans *= i;
        }
    }

    printf(I64 "\n", ans);
    
    return 0;
}
