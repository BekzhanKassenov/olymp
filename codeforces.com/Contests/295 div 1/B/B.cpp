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
const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    int x, y;
    int digit;

    Point() { }

    Point(int x, int y) : x(x), y(y), digit(-1) { }

    bool operator < (const Point& other) const {
        return digit < other.digit;
    }
};

ostream& operator << (ostream& out, const Point& p) {
    out << "({" << p.x << ", " << p.y << "}, " << p.digit << ')';
    return out;
}

struct Compare {
    bool operator () (const Point& a, const Point& b) const {
        if (a.x != b.x) {
            return a.x < b.x;
        }

        return a.y < b.y;
    }
};

set <Point> available;
set <Point, Compare> unavailable;
set <Point, Compare> global;
int n, ans;
Point a[MAXN];

int get_lower(const Point& p) {
    return global.count(Point(p.x - 1, p.y - 1)) +
           global.count(Point(p.x, p.y - 1)) +
           global.count(Point(p.x + 1, p.y - 1));
}

bool check(const Point& p) {
    for (int i = -1; i <= 1; i++) {
        Point temp(p.x + i, p.y + 1);
        
        if (global.count(temp) && get_lower(temp) == 1) {
            return false;
        }
    }

    return true;
}

void add_and_erase(const set <Point>::iterator& it) {
    Point p = *it;
    available.erase(it);
    global.erase(p);
    ans = (1ll * ans * n + p.digit) % MOD;

    for (int i = -2; i <= 2; i++) {
        if (i == 0) {
            continue;
        }

        Point temp(p.x + i, p.y);

        if (global.count(temp) && !check(temp)) {
            set <Point>::iterator to_erase = available.find(*global.find(temp));

            if (to_erase != available.end()) {
                unavailable.insert(*to_erase);
                available.erase(to_erase);
            }
        }
    }

    for (int i = -1; i <= 1; i++) {
        Point temp(p.x + i, p.y - 1);

        if (unavailable.count(temp) && check(temp)) {
            set <Point>::iterator to_add = unavailable.find(temp);
            available.insert(*to_add);
            unavailable.erase(to_add);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i].digit = i;
        scanf("%d%d", &a[i].x, &a[i].y);
        unavailable.insert(a[i]);
        global.insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (check(a[i])) {
            available.insert(a[i]);
            unavailable.erase(a[i]);
        }
    }

    while (!available.empty()) {
        add_and_erase(--available.end());

        if (!available.empty()) {
            add_and_erase(available.begin());
        }
    }

    printf("%d\n", ans);

    return 0;
}
