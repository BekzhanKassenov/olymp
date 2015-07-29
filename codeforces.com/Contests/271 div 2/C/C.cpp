/****************************************
**     Solution by Bekzhan Kassenov    **
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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    int x, y;

    Point() { }

    Point(int x, int y) : x(x), y(y) { }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    void rotate() {
        y *= -1;
        swap(x, y);
    }

    int len() const {
        return sqr(x) + sqr(y);
    }

    int operator * (const Point& p) const {
        return x * p.x + y * p.y;
    }

    bool operator < (const Point& p) const {
        if (x != p.x)
            return x < p.x;

        return y < p.y;
    }

    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }

    void read() {
        scanf("%d%d", &x, &y);
    }
};

int n, ans;
Point p[4], h[4], t[4];

bool check() {
    vector <Point> vec(t, t + 4);

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++)
            if (vec[i] == vec[j])   
                return false;
    }

    sort(all(vec));

    do {
        Point vec1 = vec[1] - vec[0];
        Point vec2 = vec[2] - vec[0];

        if (vec1.len() == vec2.len() && vec1 * vec2 == 0 &&
            vec[0] + vec1 + vec2 == vec[3])
                return true;

    } while (next_permutation(all(vec)));

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            p[j].read();
            h[j].read();
            t[j] = p[j] - h[j];
        }

        int ans = -1;

        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                for (int c = 0; c < 4; c++) {
                    for (int d = 0; d < 4; d++) {
                        for (int j = 0; j < 4; j++)
                            t[j] = t[j] + h[j];

                        if (check() && (ans == -1 || ans > a + b + c + d))
                            ans = a + b + c + d;
                            
                        for (int j = 0; j < 4; j++)
                            t[j] = t[j] - h[j];

                        t[3].rotate();
                    }

                    t[2].rotate();
                }

                t[1].rotate();
            }

            t[0].rotate();
        }

        printf("%d\n", ans);
    }

    return 0;
}
