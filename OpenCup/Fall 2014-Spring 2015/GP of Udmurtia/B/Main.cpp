/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x1, x2, y1, y2;
    ll ans = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y2 - y1 < 0) {
        swap(y2, y1);
        swap(x2, x1);
    }
    if (x1 - x2 < 0) {
        int dx = abs(x1-x2);
        int dy = abs(y1-y2);
        if (dx > dy) {
            dx -= dy;
            cout << 1 + 3*dx + 3*max(dy, 2);
        }
        else {
            dy -= dx;
            swap(dx, dy);
            cout << 1 + 3*dx + 3*max(dy, 2);            
        }
    }
    else {
    }
    return 0;
}
