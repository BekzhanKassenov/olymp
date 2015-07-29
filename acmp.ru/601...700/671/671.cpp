#include <iostream>
#include <cstdio>

using namespace std;

long long n;
int ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%I64d", &n);

    for (int len = 1; len < 11; len++) {
        for (int mask = 0; mask < (1 << len); mask++) {
            long long num = 0;

            for (int i = 0; i < len; i++) {
                num *= 10;

                if (mask & (1 << i)) {
                    num += 4;
                } else {
                    num += 7;
                }
            }

            if (num <= n) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
