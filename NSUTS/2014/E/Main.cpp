/****************************************
**          Solution by NU #2          **
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

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y, z;

    Point() { }

    Point(double x, double y, double z) : x(x), y(y), z(z) { }

    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }

    double len() const {
        return sqrt(sqr(x) + sqr(y) + sqr(z));
    }

    void make_len(double ll) {
        double rat = ll / len();

        x *= rat;
        y *= rat;
        z *= rat;
    }

    Point cross(const Point& p) const {
        Point res;

        res.x = y * p.z - z * p.y;
        res.y = z * p.x - x * p.z;
        res.z = x * p.y - y * p.x;

        return res;
    }

    void norm() {
        double l = len();
        x /= l;
        y /= l;
        z /= l;
    }

    double dot(const Point& p) const {
        return x * p.x + y * p.y + z * p.z;
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y, z + p.z);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y, z - p.z);
    }
};

Point center;
double R;
Point bender, light;

ostream& operator << (ostream& c, const Point& p) {
    c << p.x << ' ' << p.y << ' ' << p.z;
    return c;
}

double angle(const Point& p1, const Point& p2) {
    double dot = p1.dot(p2);
    Point temp = p1.cross(p2);
    double cr = temp.len();

    return atan2(cr, dot);
}

double angle2(double a) {
    assert(a);
    double an = R / a;
    return asin(an);
}

double get_ans(const Point& p) {
    double angleA, angleB;
    Point temp = (center - bender);
    
    double tempA = temp.len(); 
    angleB = abs(angle2(tempA));
    
    Point temp1 = center + p - bender;
    angleA = abs(angle(temp1, temp));
    
    //cout << "P " << p << endl;
    //cout << angleA << ' ' << angleB << endl;

    assert(angleB);
    return angleA / angleB;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    center.read();
    scanf("%lf", &R);
    bender.read();
    light.read();

    Point l = light - center;
    Point r = bender - center;

    //double lenl = l.len();
    //double lenr = r.len();

    l.make_len(R);
    r.make_len(R);

    int i = 0;
    while (true) {
        i++;
        Point mid = l + r;
        mid.make_len(R);

        Point m = center + mid;

        Point vec1 = light - m;
        Point vec2 = bender - m;

        vec1.norm();
        vec2.norm();

        Point cross1 = vec1.cross(mid);
        Point cross2 = mid.cross(vec2);

        double angle1 = cross1.len();
        double angle2 = cross2.len();

        if (angle1 > angle2)
            r = mid;
        else
            l = mid;

        //cerr << angle1 << ' ' << angle2 << ' ' << mid << endl;

        if (i >= 30)
            break;
    }

    double ans = get_ans(l);

    printf("%.14lf\n", ans);

    return 0;
}
