/****************************************
**     Solution by Bekzhan Kassenov    **
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

void print(int _x1, int _y1,
           int _x2, int _y2,
           int _x3, int _y3) {
    int vx1 = _x1 - _x2;
    int vy1 = _y1 - _y2;

    int vx2 = _x3 - _x2;
    int vy2 = _y3 - _y2;

    cout << _x2 + vx1 + vx2 << ' ' << _y2 + vy1 + vy2 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int _x1, _y1;
    cin >> _x1 >> _y1;

    int _x2, _y2;
    cin >> _x2 >> _y2;

    int _x3, _y3;
    cin >> _x3 >> _y3;

    cout << 3 << endl;
    print(_x1, _y1, _x2, _y2, _x3, _y3);
    print(_x1, _y1, _x3, _y3, _x2, _y2);
    print(_x2, _y2, _x1, _y1, _x3, _y3);

    return 0;
}
