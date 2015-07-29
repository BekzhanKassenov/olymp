#include <cstdio>
#include <cmath>

using namespace std;

long long n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%I64d", &n);

    long long lose = 0;
    for (long long cur = 2; lose <= n; cur++) {
        if (lose == n) {
            puts("LOSE");
            return 0;
        }

        lose += cur;

        if (lose == n) {
            puts("LOSE");
            return 0;
        }

        if (!(cur & (cur - 1))) {
            continue;
        }

        lose += cur;
    }

    puts("WIN");

    return 0;
}
