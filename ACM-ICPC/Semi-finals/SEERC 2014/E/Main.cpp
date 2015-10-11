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

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    long long x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) { }

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

    double distTo(const Point& p) const {
        long long z = min(abs(x - p.x), abs(y - p.y));
        long long t = max(abs(x - p.x), abs(y - p.y));

        return (double)(t - z) + sqrt(2.0) * z;
    }

    bool operator < (const Point& p) const {
        long long mul = this->cross(p);

        if (mul == 0) {
            return len() < p.len();
        }

        return mul > 0;
    }

    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }

    void read() {
        cin >> x >> y;
    }
};  

ostream& operator << (ostream& out, const Point& p) {
    out << p.x << ' ' << p.y;
    return out;
}

double convex(vector <Point>& a) {
    int pos = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (a[i].x < a[pos].x || (a[i].x == a[pos].x && a[i].y < a[pos].y)) {
            pos = i;
        }
    }

    swap(a[pos], a[0]);
    for (int i = n - 1; i >= 0; i--) {
        a[i] = a[i] - a[0];
    }

    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    n = a.size();

    stack <Point, vector <Point> > st;
    st.push(a[0]);
    st.push(a[1]);

    for (int i = 2; i < n; i++) {
        Point C = a[i];

        while ((int)st.size() > 1) {

            Point B = st.top();
            st.pop();
            Point A = st.top();

            if (!(C - A < B - A)) {
                st.push(B);
                break;
            }
        }

        st.push(C);
    }

    Point temp = st.top();
    Point prev = st.top();
    st.pop();

    double ans = 0;
    while (!st.empty()) {
        ans += st.top().distTo(prev);
        prev = st.top();
        st.pop();
    }
    ans += temp.distTo(prev);

    return ans;
}

int n;
Point p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            p[i].read();
        }

        vector <Point> vec;

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 4; k++) {
                vec.push_back(Point(p[i].x + dx[k], p[i].y + dy[k]));
            }
        }

        cout << setprecision(10) << fixed;
        cout << convex(vec) << endl;
    }
    
    return 0;
}
