#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x, y;

    cin >> n >> x >> y;

    if (x > y)
        swap(x, y);

    int ans = x;
    n--;

    int l = lcm(x, y);

    int cnt = l / x + l / y;

    ans += l * (n / cnt);

    n %= cnt;

    int res = (int)1e9;

    for (int i = 0; i <= n; i++) {
        res = min(res, max(i * x, (n - i) * y));
    }

    cout << ans + res;

    return 0;
}
