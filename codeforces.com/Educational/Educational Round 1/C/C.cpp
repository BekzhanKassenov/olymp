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
    int x, y;
    int idx;
};

Point OX = {1, 0, 0};

Point operator - (const Point& lhs, const Point& rhs) {
    Point result = {lhs.x - rhs.x, lhs.y - rhs.y, 0};

    return result;
}

int n;
Point p[MAXN];
double ans = 10000;
int ansi, ansj = 1;

double angle(const Point& b) {
    double ans = atan2(b.y, b.x);

    if (ans < 0) {
        ans += 2 * PI;
    }

    return ans;
}

bool compare(const Point& lhs, const Point& rhs) {
    return angle(lhs) < angle(rhs);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].idx = i + 1;
    }

    sort(p, p + n, compare);

    for (int i = 0; i < n; i++) {
        if (abs(angle(p[i]) - angle(p[(i + 1) % n])) < ans) {
            ans = abs(angle(p[i]) - angle(p[(i + 1) % n]));
            ansi = i;
            ansj = (i + 1) % n;
        }
    }

    printf("%d %d\n", p[ansi].idx, p[ansj].idx);

    return 0;
}
