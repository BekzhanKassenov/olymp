/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

inline ll sqr(int n) {
    return n * 1ll * n;
}
                                    
struct Point {
    int x, y;

    bool operator < (const Point& p) const {
        return y < p.y;
    }

    ll dist_to(const Point& p) const {
        return sqr(x - p.x) + sqr(y - p.y);
    }
};

Point a[maxn];
int n, x, sum;
ll minans = INF * 1ll * INF;

inline void update(Point* p1, Point* p2) {
    minans = min(minans, p1 -> dist_to(*p2));
}

inline void go(Point* l, Point* r) {
    if (r - l < 3) {
        for (Point *i = l; i != r; i++)
            for (Point *j = i + 1; j != r; j++)
                update(i, j);

        sort(l, r);
        return;
    }

    Point *mid = l + ((r - l) >> 1);
    int midx = mid -> x;
    int buf_size = 0;

    go(l, mid);
    go(mid, r);

    static Point buf[maxn];
    copy(buf, merge(l, mid, mid, r, buf), l);

    for (Point *i = l; i != r; i++) {
        if (sqr(abs(i -> x - midx)) < minans) {
            for (int j = buf_size - 1; j >= 0 && sqr(i -> y - buf[j].y) < minans; j--)
                update(i, buf + j);

            buf[buf_size++] = *i; 
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        a[i].x = i + 1;
        a[i].y = sum;
    }

    go(a, a + n);

    printf("%I64d", minans);

    return 0;
}
                                