#include <iostream>
#include <cstdio>

using namespace std;

long long f(long long n) {
    return n / 10;
}

long long calc(long long l, long long r) {
    if (l > r) {
        return 0;
    }

    long long cnt = f(r) - f(l - 1);

    //cout << l << ' ' << r << ' ' << cnt << endl;

    return cnt + calc(r + 1, r + cnt);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    if (n == 1) {
        puts("1");
        return 0;
    }

    long long start = 2;
    for (int i = 3; i <= n; i++) {
        start += 2 * ((i - 1) / 2) + 1;
    }

//    cout << calc(1, 100) << endl;

    start += calc(1, start);

    printf("%I64d\n", start);

    return 0;
}
