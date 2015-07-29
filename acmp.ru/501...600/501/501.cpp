#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    
    Point() {}

    Point(int x, int y): x(x), y(y) {}
};

struct pr {
    Point first, second;

    pr() {}
};

inline bool in(const Point& a, const pr& b) {
    if (a.x > b.first.x && a.x <= b.second.x)
        if (a.y > b.first.y && a.y <= b.second.y)
            return true;

    return false;
}

istream& operator >> (istream& c, Point& p) {
    c >> p.x >> p.y;
    return c;
}

istream& operator >> (istream& c, pr& p)
{
    c >> p.first >> p.second;

    int x = min(p.first.x, p.second.x);
    int y = min(p.first.y, p.second.y);

    int x1 = max(p.first.x, p.second.x);
    int y1 = max(p.first.y, p.second.y);
    
    p.first = Point(x, y);
    p.second = Point(x1, y1);

    return c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    vector <pr> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    pr cur;

    cin >> cur;

    int ans = 0;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            Point p(i, j);

            int cnt = 0;

            for (int k = 0; k < n; k++) {
                if (in(p, a[k]))
                    cnt++;
            }

            if (cnt && in(p, cur)) 
                 ans += cnt;
        }
    }

    cout << ans;
    
    return 0;
}
