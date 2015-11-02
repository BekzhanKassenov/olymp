/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "quadr"

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

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    int len() const {
        return sqr(x) + sqr(y);
    }

    int dot(const Point& p) const {
        return x * p.x + y * p.y;
    }

    void read() {
        scanf("%d%d", &x, &y);
    }
};

bool quadr(const vector <Point>& a) {
    int len = (a[1] - a[0]).len();

    for (int i = 0; i < 4; i++) {
        Point vprev = a[i] - a[(i - 1 + 4) % 4];
        Point vnext = a[(i + 1) % 4] - a[i];

        if (vprev.dot(vnext) != 0) {
            return false;
        }

        if (vprev.len() != len || vnext.len() != len) {
            return false;
        }
    }

    return true;
}

Point p[4];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    for (int i = 0; i < 4; i++) {
        p[i].read();
    }

    vector <int> perm(4);
    for (int i = 0; i < 4; i++) {
        perm[i] = i;
    }

    do {
        vector <Point> temp;
        for (int i = 0; i < 4; i++) {
            temp.push_back(p[perm[i]]);
        }

        if (quadr(temp)) {
            puts("YES");
            return 0;
        }   
    } while (next_permutation(all(perm)));

    puts("NO");
    return 0;
}
