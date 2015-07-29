#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(a) ((a)*(a))
#define PI acos(-1.0)
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    double v, x1, x2, x3, y1, y2, y3, z1, z2, z3, r2, d2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> v;
    r2 = sqr(x1) + sqr(y1) + sqr(z1);
        d2 = sqr(x2) + sqr(y2) + sqr(z2); 
 
    x3 = x2 * sqrt(r2/d2);
    y3 = y2 * sqrt(r2/d2);
    z3 = z2 * sqrt(r2/d2);
        double dx = x1-x3, dy = y1-y3, dz = z1-z3;                 
        double dt = 1000000.0, ans = 1000000000.0;
        dx /= dt;
        dy /= dt;
        dz /= dt;   
        for (int i = 0; i < 1000000; ++i){
            double x4 = (double)i*dx + x3, y4 = (double)i*dy + y3, z4 = (double)i*dz + z3;
            double dist1, dist2;
                if (sqr(x4-x1) + sqr(y4-y1) + sqr(z4-z1) <= d2-r2)
                    dist1 = sqrt(sqr(x4-x1) + sqr(y4-y1) + sqr(z4-z1));         
                else {
                    dist1 = sqrt(d2-r2);
                    dist1 += acos((x4*x3+y4*y3+z4*z3)/r2)-acos(sqrt(r2/d2));
                }
                dist2 = acos((x4*x1+y4*y1+z4*z1)/r2);
                if (abs(dist2-dist1/v) < 0.001){
                    cout << dist1/v; return 0;
                }
    }
    return 0;
}