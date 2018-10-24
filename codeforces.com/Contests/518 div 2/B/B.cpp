/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    long long b;
    cin >> b;

    long long ans = 1;
    long long n = b;
    for (long long i = 2; i * i <= b; i++) {
        long long cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        ans *= (cnt + 1);
    }

    if (n > 1) {
        ans *= 2;
    }

    cout << ans << endl;
    
    return 0;
}
