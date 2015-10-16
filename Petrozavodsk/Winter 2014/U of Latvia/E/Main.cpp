/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = (long long) 1e18;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    long long x, y;

    Point (long long x = 0, long long y = 0) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
                                
    long long cross(const Point& p) const {
        return x * p.y - y * p.x;
    }

    long long len() const {
        return sqr(x) + sqr(y);
    }

    bool operator < (const Point& p) const {
        if (this->cross(p) != 0) {
            return this->cross(p) > 0;
        }

        return len() < p.len();
    }
};

int n;
Point p[MAXN];

void get_convex(vector <Point>& vec) {
    Point diff = p[0];

    for (int i = 1; i < n; i++) {
        if (p[i].x < diff.x || (p[i].x == diff.x && p[i].y < diff.y)) {
            diff = p[i];
        }
    }

    for (int i = 0; i < n; i++) {
        p[i] = p[i] - diff;
    }

    sort(p, p + n);

    vec.push_back(p[0]);
    vec.push_back(p[1]);

    for (int i = 2; i < n; i++) {
        while (vec.size() > 1u) {
            Point cur = vec.back();
            vec.pop_back();

            Point vec1 = p[i] - vec.back();
            Point vec2 = cur - vec.back();

            if (vec1.cross(vec2) < 0) {
                vec.push_back(cur);
                break;
            }
        }

        vec.push_back(p[i]);
    }   

    for (auto& p: vec) {
        p = p + diff;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(I64 I64, &p[i].x, &p[i].y);
        
        if (p[i].x < 0) {
            p[i].x *= -1;
            p[i].y *= -1;
        }
    }

    if (n == 2) {
        printf(I64 "\n", abs(p[0].cross(p[1])));
        return 0; 
    }

    vector <Point> convex;
    get_convex(convex);

    long long ans = 0;
    for (size_t l = 0, r = 0; l < convex.size(); l++) {
        long long area = abs(convex[l].cross(convex[r]));
        ans = max(ans, area);

        while (r + 1 != l && abs(convex[l].cross(convex[(r + 1) % convex.size()])) >= area) {
            r = (r + 1) % convex.size();
            area = abs(convex[l].cross(convex[r]));
            ans = max(ans, area);
        }
    }

    printf(I64 "\n", ans);
    
    return 0;
}
