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
#define File "area"

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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}


double sqared_area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    
    return p * (p - a) * (p - b) * (p - c);
}
/*double f(double x, double r) {
    x -= r;
    assert(abs(x) <= abs(r));
    double S = sqr(sqared_area())
    return sqr(r) / 2.0 * (2.0 * asin(x / r) - sin(2.0 * asin(x / r)) + pi);
}
*//*
double f(double x, double r) {
    x -= r;
    assert(abs(x) <= abs(r));
    double n = 2.0*sqrt(sqr(r) - sqr(x));
    double S = 0.5*n*abs(x);
    double a = atan2((2.0*sqr(x) - sqr(r)), (2.0*S));
//    a += pi/2.0;
  //  a /= 2.0;
        
    double s1 = a / 2.0 * sqr(r) - S;
            cout << a << " " ;
    if (x > 0.0)
        s1 = pi * sqr(r) - s1;
    
    return s1;
}*/
double f(double x, double r) {
    x -= r;
    assert(abs(x) <= abs(r));
    double n = 2.0*sqrt(sqr(r) - sqr(x));
    double S = 0.5*n*abs(x);
    double a;
    if (x < 0.0){
        a = (pi - atan2(sqrt(sqr(r)-sqr(x)), x))*2.0;
    }
    else
        a = atan2(sqrt(sqr(r)-sqr(x)), x)*2.0;
        
    double s1 = a / 2.0 * sqr(r) - S;
    if (x > 0.0)
        s1 = pi * sqr(r) - s1;
    
    return s1;
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    double x, y, _x, _y, r1, r2;
    
    cin >> x >> y >> r1 >> _x >> _y >> r2;
    
    double sqr_dist = sqr(x - _x) + sqr(y - _y);
    double dist = sqrt(sqr_dist);
    
    if (sqr_dist >= sqr(r1 + r2)) {
        puts("0.00");
    } else if (sqr_dist <= sqr(r1 - r2)) {
        printf("%.2lf", sqr(min(r1, r2)) * pi);
    } else if (abs(sqr(r1) - sqr(r2)) <= sqr_dist) {
        double u = sqrt(sqared_area(dist, r1, r2))*2.0/dist;
        double t1 = r1 - sqrt(sqr(r1) - sqr(u));
        double t2 = r2 - sqrt(sqr(r2) - sqr(u));
        printf("%.2lf", f(t1, r1) + f(t2, r2));
    } else {
        if (r1 > r2) 
            swap(r1, r2);
            
        double x = (sqr(r2) - sqr(r1) - sqr_dist) / (2.0 * dist);
        
            
        printf("%.2lf", pi * sqr(r1) - f(r1 - x, r1) + 
                                       f(r2 - dist - x, r2));
    }
    
    return 0;
}
