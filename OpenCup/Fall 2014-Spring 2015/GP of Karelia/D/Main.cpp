/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File ""

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
};

void gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

struct Line {
    int a, b, c;

    Line() { }

    Line(int a, int b, int c) : a(a), b(b), c(c) {
        normalize();
    }

    void normalize() {
        int g = gcd(gcd(abs(a), abs(b)), abs(c));
        a /= g;
        b /= g;
        c /= g;
        
        if (a < 0 || (a == 0 && b < 0)) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
    }
};

bool parallel(const Line& lhs, const Line& rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b;
}

bool equal(const Line& lhs, const Line& rhs) {
    return parallel(lhs, rhs) && lhs.c == rhs.c;
}

bool zero_intersect(const Line& lhs, const Line& rhs) {
    return lhs.b  * rhs.c == rhs.b * lhs.c;
}

int main() {
    freopen(File".in", "r", stdin);
    
    return 0;
}
