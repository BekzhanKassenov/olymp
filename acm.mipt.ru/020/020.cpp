#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

const int MAXN = 210;

struct Point {
    long long x, y;

    void read() {
        cin >> x >> y;
    }

    Point(long long x = 0, long long y = 0) : x(x), y(y) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }

    long long cross(const Point& p) const {
        return x * p.y - y * p.x;
    }

    long long dot(const Point& p) const {
        return x * p.x + y * p.y;
    }

    long long len() const {
        return x * x + y * y;
    }
    
    bool between(const Point& l, const Point& r) const {
        if (*this == l || *this == r) {
            return true;
        }

        Point vec1 = *this - l;
        Point vec2 = r - *this;

        return vec1.cross(vec2) == 0 && vec1.dot(vec2) > 0;
    }
};

int sign(double val) {
    return (val > 0) - (val < 0);
}

bool inter(const Point& a, const Point& b, const Point& c, const Point& d) {
    Point vec1 = a - b;
    Point vec2 = c - d;
    
    if (vec1.cross(vec2) == 0) {
        return a.between(c, d) || b.between(c, d) || c.between(a, b) || d.between(a, b);
    }

    return sign(vec1.cross(c - a)) != sign(vec1.cross(d - a)) && sign(vec2.cross(a - c)) != sign(vec2.cross(b - c));
}

struct Edge {
    int from, to;
    double len;

    bool operator < (const Edge& p) const {
        return len < p.len;
    }
};

int parent[MAXN];

int get_parent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = get_parent(parent[v]);
}

bool unite(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[a] = b;
        return true;
    }

    return false;
}

Point a[MAXN], l[MAXN], r[MAXN];
string name[MAXN];
Edge e[MAXN * MAXN];
int n, m, lastEdge;
vector <int> ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        a[i].read();
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        l[i].read();
        r[i].read();
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool found = false;
            for (int k = 0; k < m && !found; k++) {
                if (inter(a[i], a[j], l[k], r[k])) {
                    found = true;
                }
            }

            if (!found) {
                e[lastEdge].from = i;
                e[lastEdge].to = j;
                e[lastEdge].len = (a[i] - a[j]).len(); 
                lastEdge++;
            }
        }
    }

    sort(e, e + lastEdge);
    for (int i = 0; i < lastEdge; i++) {
        if (unite(e[i].from, e[i].to)) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (unite(i, j)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;

    for (size_t i = 0; i < ans.size(); i++) {
        cout << name[e[ans[i]].from] << ' ' << name[e[ans[i]].to] << endl;
    }

    return 0;
}
