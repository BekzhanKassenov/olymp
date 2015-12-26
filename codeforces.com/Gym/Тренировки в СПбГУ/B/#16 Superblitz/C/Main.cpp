#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 20010;

template <typename T>
inline T sqr(T x) {
    return x * x;
}

struct Point {
    double x, y;

    Point() { }

    Point(double x, double y) : x(x), y(y) { }

    void read() {
        scanf("%lf %lf", &x, &y);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point& operator -= (const Point& p) {
        x -= p.x;
        y -= p.y;
        
        return *this;
    }

    double operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }

    bool operator < (const Point& p) const {
        if ((*this) * p != 0) {
            return (*this) * p > 0;
        }

        return this->dist_to_zero() < p.dist_to_zero();
    }

    double dist_to_zero() const {
        return sqrt(sqr(x) + sqr(y));
    }

    double dist_to(const Point&p) const {
        return (*this - p).dist_to_zero();
    }
};

ostream& operator << (ostream& out, const Point& p) {
    out << '{' << p.x << ", " << p.y << '}';
    return out;
}

int n;
Point a[MAXN], minpoint;
vector <Point> st;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        a[i].read();
    }

    minpoint = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].x < minpoint.x ||
            (a[i].x == minpoint.x && a[i].y < minpoint.y)) {
            minpoint = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] -= minpoint;
    }
    
    sort(a, a + n);

    st.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        while ((int)st.size() > 1) {
            Point temp = st.back();
            st.pop_back();

            if ((a[i] - st.back()) * (temp - st.back()) < 0) {
                st.push_back(temp);
                break;
            }
        }

        st.push_back(a[i]); 
    }

    double len = 0.0;
    
    for (size_t i = 0; i < st.size(); i++) {
        //cout << st[i] << endl;
        len += st[i].dist_to(st[(i + 1) % st.size()]);
    }

    printf("%.15f\n", len);

    return 0;
}
