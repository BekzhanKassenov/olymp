/****************************************
**        Solution by NU PTZ 2016      **
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

const double EPS = 1e-5;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;

    Point(double x = .0, double y = .0) : x(x), y(y) { }

    void read() {
        scanf("%lf%lf", &x, &y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    double distToSqr(const Point& p) const {
        return sqr(x - p.x) + sqr(y - p.y);
    }

    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
};

int n;
Point dist1[MAXN], dist2[MAXN];
Point clos1[MAXN], clos2[MAXN];
Point center[MAXN];
vector <vector<Point> > rect[MAXN];
int ans[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        dist1[i].read();
        dist2[i].read();
        clos1[i].read();
        clos2[i].read();

        int cnt;
        scanf("%d", &cnt);
        rect[i].resize(cnt);
        for (auto& tp: rect[i]) {
            for (int j = 0; j < 4; j++) {
                Point vertex;
                vertex.read();
                tp.push_back(vertex);
            }
        }
    }

    vector<pair<double, int>> classes;
    for (int i = 0; i < n; i++) {
        double a = dist1[i].distToSqr(dist2[i]);
        double b = clos1[i].distToSqr(clos2[i]);
        double sumArea = 0;
        for (auto& tp: rect[i]) {
            sumArea += abs((tp[0] - tp[1]).cross(tp[2] - tp[1]));
        }
        classes.emplace_back(sqrt(a) * sqrt(b) / sumArea, i);
    }

    sort(all(classes));
    ans[classes[0].second] = 1;
    int last = 1;
    for (int i = 1; i < n; i++) {
        if (abs(classes[i].first - classes[i - 1].first) < EPS) {
            ans[classes[i].second] = last;
        } else {
            ans[classes[i].second] = ++last;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    puts("");

    return 0;
}
