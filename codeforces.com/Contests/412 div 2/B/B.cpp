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

int p, x, y;
bool is[510];

int f(int x) {
    return (x / 50) % 475;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> p >> x >> y;

    for (int i = 0; i < 475; i++) {
        int num = i;
        for (int j = 0; j < 25; j++) {
            num = (num * 96 + 42) % 475;
            if (num + 26 == p) {
                is[i] = true;
            }
        }
    }

    int cur = x;
    while (cur >= y) {
        if (is[f(cur)]) {
            cout << 0 << endl;
            return 0;
        }
        cur -= 50;
    }

    cur = x;
    while (!is[f(cur)]) {
        cur += 50;
    }

    int ans = (cur - x) / 50;
    ans += ans & 1;

    cout << ans / 2 << endl;
    
    return 0;
}
