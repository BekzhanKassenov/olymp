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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int comp(double a, double b) {
    if (fabs(b - a) <= EPS)
        return 0;
        
    if (a - b > 0)
        return 1;
        
    return -1;
}

struct Point {
    double x, y;
    
    Point() : x(0), y(0) { }
    
    Point(double x, double y) : x(x), y(y) { }
    
    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator - () const {
        return Point(-x, -y);
    }
    
    double operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }
    
    double operator ^ (const Point& p) const {
        return x * p.x + y * p.y;
    }
    
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    
    double sqr_len() const {
        return sqr(x) + sqr(y);
    }
    
    void make_len(double len) {
        double cur_len = sqrt(sqr_len());
        x /= cur_len;
        y /= cur_len;
        
        x *= len;
        y *= len;
    }
    
    Point get_closest(const Point& p1, const Point& p2) {
        if (comp((*this - p1) ^ (p2 - p1), 0) <= 0) {
            return p1;
        } 
        
        if (comp((*this - p2) ^ (p1 - p2), 0) <= 0) {
            return p2;
        }
        
        double a = p2.y - p1.y;
        double b = p1.x - p2.x;
        double c = -a * p2.x - b * p2.y;
        
        double d = sqrt(sqr(a) + sqr(b));
        
        a /= d;
        b /= d;
        c /= d;
        
        Point norm(a, b);
        
        double dist = abs((p1 - *this) * (p2 - *this)) / (sqrt((p1 - p2).sqr_len()));
        
        norm.make_len(dist);
        
        Point ans = (*this) + norm;
        
        if (comp(a * ans.x + b * ans.y + c, 0) != 0)
            ans = (*this) - norm;
            
        return ans;
    }
};

int n, m;
Point fig[maxn], gen[maxn], cent;

int main() {
#ifndef ONLINE_JUDGE    
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        gen[i].read();
        cent = cent + gen[i];
    }
    
    cent.x /= n;
    cent.y /= n;
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++)
        fig[i].read();
        
    bool flag = true;
    
    for (int i = 0; i < m && flag; i++) {
        Point p1 = fig[(i + 1) % m] - fig[i];
        Point p2 = cent - fig[i];
        
        if (comp(p1 * p2, 0) >= 0)
            flag = false;
    }
    
    if (!flag) {
        double dist = 1e18;
        Point ans_point = cent;
        
        for (int i = 0; i < m; i++) {
            Point temp = cent.get_closest(fig[i], fig[(i + 1) % m]);
            
            if (comp((cent - temp).sqr_len(), dist) < 0) {
                dist = (cent - temp).sqr_len();
                ans_point = temp;
            }
        }
        cent = ans_point;
    }
    
    double ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += (gen[i] - cent).sqr_len();
    }
    
    printf("%.15lf", ans);
    
    return 0;
}
