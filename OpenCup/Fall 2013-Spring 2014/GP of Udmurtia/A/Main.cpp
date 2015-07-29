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

struct Point {
    int x, y;
    
    Point() { }
    
    Point (int x, int y) : x(x), y(y) { }
    
    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    
    ll operator * (const Point& p) const {
        return (x * 1ll * p.y - y * p.x);
    }
};

struct st {
    Point p;
    int s, n;
    
    void read() {
        scanf("%d%d%d", &p.x, &p.y, &s);
    }
    
    bool operator < (const st& str) const {
        return (s > str.s);
    }
}; 

const int maxn = 100010;

st a[maxn];
int n;

bool on_line(const Point& a, const Point& b, const Point& c) {
    Point t1 = a - b;
    Point t2 = c - b;
    
    return (t1 * t2 == 0);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        a[i].read();
        a[i].n = i + 1;
    }
    
    sort(a, a + n);
    
    
    for (int i = 2; i < n; i++) {
        if (!on_line(a[0].p, a[1].p, a[i].p)) {
            cout << a[0].s + a[1].s + a[i].s << endl;
            cout << a[0].n << ' ' << a[1].n << ' ' << a[i].n << endl;
            break;
        }
    }
    
    return 0;
}
