#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    freopen("train.in", "r", stdin);
    freopen("train.out", "w", stdout);

    int n, m, f, l;

    while (cin >> n >> m >> f >> l && (n || m || f || l)) {
        double lmf = sqrt((l * m + .0) / (f + .0)), ans = 0, k = 0;

        for (int i = 2; i <= n; i++) {
            k = sqrt(2.0 / (i + .0) + k * k) - k;
            ans += k * (i + .0) * lmf;
        }

        cout << (int)ceil(ans) << endl;
    }

    cout << endl;

    return 0;
}