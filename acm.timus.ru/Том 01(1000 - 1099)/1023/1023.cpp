#include <iostream>
#include <cstdio>

using namespace std;

int k;

bool check(int num) {
    return 2 <= num && num < k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &k);

    int ans = k - 1;
    for (int i = 1; i * i <= k; i++) {
        if (k % i != 0) {
            continue;
        }

        if (check(i - 1)) {
            ans = min(ans, i - 1);
        }

        if (check(k / i - 1)) {
            ans = min(ans, k / i - 1);
        }
    }

    printf("%d\n", ans);

    return 0;
}
