/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "polygon"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const double INF = 1e100;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

double ans;

int sign(double n) {
    if (fabs(n) < EPS)
        return 0;
        
    if (n < 0)
        return -1;
        
    return 1;
}

struct Point {
    double x, y;
    
    Point() { }
    
    Point(double x, double y) : x(x), y(y) { }
    
    Point(const Point& p) {
        *this = p;
    }
    
    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    
    double operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }
    
    double len() const {
        return sqr(x) + sqr(y);
    }
    
    void get_line(const Point& p, double& a, double& b, double& c) const {
        a = p.y - y;
        b = x - p.x;
        c = -x * p.y + y * p.x;
    }
    
    void try_intersect(const Point& l, const Point& r) const {
        if (sign((*this) * l) * sign((*this) * r) <= 0) {
            double a1, b1, c1;
            get_line(Point(0, 0), a1, b1, c1);
            
            double a2, b2, c2;
            l.get_line(r, a2, b2, c2);
            
            double _y = (a1 * c2 - c1 * a2) / (a2 * b1 - a1 * b2);
            double _x = 0;
            
            if (a1 != 0)
                _x = -b1 / a1 * _y - c1 / a1;
            else
                _x = -b2 / a2 * _y - c2 / a2;
                
            ans = min(ans, sqrt(len() * Point(_x, _y).len()));
        }
    }
    
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};  

int n;
Point a[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        a[i].read();
        
    Point p1(a[0]), p2(a[0]);
    
    for (int i = 0; i < n; i++) {
        if (p1 * a[i] < 0)
            p1 = a[i];
            
        if (p2 * a[i] > 0)
            p2 = a[i];
    }
    
    ans = min(p1.len(), p2.len());
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && i != (j + 1) % n)
                a[i].try_intersect(a[j], a[(j + 1) % n]);
        }
    }
    
    printf("%.10lf", ans);
    
    return 0;
}
