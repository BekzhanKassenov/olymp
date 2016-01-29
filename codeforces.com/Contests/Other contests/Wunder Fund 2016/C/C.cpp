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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    long double x, y;
    int num;

    Point(long double x = 0, long double y = 0) : x(x), y(y) { }
    
    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point& operator -= (const Point& p) {
        x -= p.x, y -= p.y;

        return *this;
    }

    int operator * (const Point& p) const {
        long double res1 = x;
        res1 *= p.y;

        long double res2 = y;
        res2 *= p.x;

        if (res1 > res2) {
            return 1;
        }

        if (res1 < res2) {
            return -1;
        }

        return 0;
    }

    long double len() const {
        return sqr(x) + sqr(y);
    }

    bool operator < (const Point& p) const {
        if (*this * p == 0) {
            return len() < p.len();
        }

        return *this * p > 0;
    }
};                                 

int n;
Point p[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].num = i + 1;
    }   

    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].x < p[pos].x || (p[i].x == p[pos].x && p[i].y < p[pos].y)) {
            pos = i;
        }
    }

    swap(p[pos], p[0]);
    for (int i = n - 1; i >= 0; i--) {
        p[i] -= p[0];
    }

    sort(p, p + n);
    int idx = 2;

    while ((p[idx] - p[1]) * (p[1] - p[0]) == 0) {
        idx++;
    }

    printf("%d %d %d\n", p[0].num, p[1].num, p[idx].num);

    return 0;
}
