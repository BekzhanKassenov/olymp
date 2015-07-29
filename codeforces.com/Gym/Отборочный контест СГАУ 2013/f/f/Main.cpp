#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200010;

int n, p, q, a[maxn];

int check(int cnt) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - q * cnt > 0)
            c += (a[i] - q * cnt) / (p - q) + ((a[i] - q * cnt) % (p - q) != 0);
    }

    if (c == cnt)
        return 0;

    if (c < cnt)
        return -1;

    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    cin >> n >> p >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    if (p == q) {
        cout << (a[n - 1] / p) + (a[n - 1] % p != 0);
        return 0;
    }

    cout << check(5) << endl;

    int ans = (int)1e9 + 1e5;

    int l = 0, r = ans;

    while (r - l > 10) {
        int mid = (r + l) >> 1;

        int ind = check(mid);

        if (ind == 0) 
            ans = min(ans, mid);
        
        if (ind <= 0)
            r = mid;
        else
            l = mid;
    }

    for (int i = l; i <= r; i++)
        if (check(i) == 0)
            ans = min(ans, i);

    cout << ans;
    return 0;
}
