#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

inline double sqr(double x) {
    return x * x;
}

inline double dist(double x, double y, double _x, double _y) {
    return (sqrt(sqr(x - _x) + sqr(y - _y)));
}

double a, b, x, y, _x, _y;

inline double get_one_side_dist(double x, double y, double _x, double _y) {
    double ans = dist(x, y, _x, _y);
    x -= a;
    ans = min(ans, dist(x, y, _x, _y));
    x += 2 * a;
    ans = min(ans, dist(x, y, _x, _y));
    x -= a;
    _x -= a;
    ans = min(ans, dist(x, y, _x, _y));
    _x += 2 * a;
    ans = min(ans, dist(x, y, _x, _y));
    return ans;

}

int main() {
    #ifdef Local
        freopen("in", "r", stdin);
    #endif

    int t;
    cin >> t;
    
    while (t--) {
        cin >> a >> b;
        char ch1, ch2;
        double ans = 1e9;
        
        cin >> x >> y >> ch1 >> _x >> _y >> ch2;
        
        if (ch1 == ch2) {
            ans = get_one_side_dist(x, y, _x, _y);
        } else {
            double delta = b - y;
            y += 2 * delta;
            ans = min(ans, get_one_side_dist(x, y, _x, _y));
            y -= 2 * delta;
            delta = y;
            y -= 2 * delta;
            ans = min(ans, get_one_side_dist(x, y, _x, _y));
            y += 2 * delta;
            delta = b - _y;
            _y += 2 * delta;
            ans = min(ans, get_one_side_dist(x, y, _x, _y));
            _y -= 2 * delta;
            delta = _y;
            _y -= 2 * delta;
            ans = min(ans, get_one_side_dist(x, y, _x, _y));
            _y += 2 * delta;
        }

        printf("%.10lf\n", ans);
    }
    return 0;
}