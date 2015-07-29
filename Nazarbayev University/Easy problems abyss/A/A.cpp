#include <iostream>
#include <cstdio>

using namespace std;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != j) {
                ans += (n - i + 1) * (m - j + 1);
            }
        }
    }

    cout << ans;

    return 0;
}
