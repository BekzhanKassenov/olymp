#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll a[1010];

int main() {
    freopen("catalan.in", "r", stdin);
    freopen("catalan.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    a[0] = 1;

    for (int i = 1; i <= n; i++) {
        a[i] = 0;

        for (int j = 0; j < i; j++)
            a[i] = (a[i] + a[j] * a[i - j - 1] % m) % m;
    }

    cout << a[n] << endl;

    return 0;
}
