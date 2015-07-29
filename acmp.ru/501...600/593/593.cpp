#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 2010;

struct Point {
    long long x, y;
    int num;

    Point() { }

    Point(long long x, long long y) : x(x), y(y) { }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    long long operator * (const Point& p) const {
        return x * p.y - y * p.x;
    }

    void read() {
        scanf("%I64d%I64d", &x, &y);
    }

    bool operator < (const Point& p) const {
        return x < p.x;
    }
};

int n;
Point a[MAXN];
int ans[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i].read();
        a[i].num = i;
    }

    sort(a, a + n);

    for (int i = 0; i < n - 1; i++) {
        ans[a[i].num]++;
        ans[a[i + 1].num]++;
        Point cur = a[i + 1] - a[i];

        for (int j = i + 2; j < n; j++) {
            if (cur * (a[j] - a[i]) >= 0ll) {
                ans[a[i].num]++;
                ans[a[j].num]++;
                cur = a[j] - a[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}
