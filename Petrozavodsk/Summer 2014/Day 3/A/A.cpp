#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

const int MAXN = 305;

struct point {
    long long x, y;

    point() { }

    point(long long x, long long y) : x(x), y(y) { }

    point operator - (const point& p) const {
        return point(x - p.x, y - p.y);
    }

    long long operator * (const point& p) const {
        return x * p.y - y * p.x;
    }

    bool operator == (const point& p) const {
        return x == p.x && y == p.y;
    }

    bool operator < (const point& p) const {
        if (x != p.x)
            return x < p.x;

        return y < p.y;
    }
    
    void print() {
        printf("%I64d %I64d\n", x, y);
    }
};
    
int n;
point p[MAXN];

void check() {
    int bad = 0;
    for (int i = 3; i <= n; i++) {
        if ((p[i] - p[1]) * (p[2] - p[1]) != 0)
            bad++;
    }

    if (bad <= 1) {
        printf("%d\n", n);
        exit(0);
    }
}

bool parallelogram() {
    point v1, v2, v3, v4;
    v1 = p[2] - p[1];
    v2 = p[3] - p[1];
    v3 = p[4] - p[3];
    v4 = p[4] - p[2];

    return v1 == v3 && v2 == v4;
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d %I64d", &p[i].x, &p[i].y);
    }

    if (n <= 3) {
        printf("%d\n", n);
        return 0;
    }

    check();

    swap(p[1], p[3]);
    swap(p[2], p[4]);
    check();

    if (n > 5) {
        puts("oo");
        return 0;
    }

    if (n == 4) {
        sort(p + 1, p + 5);
        do {
            if (parallelogram()) {
                printf("5\n");
                return 0;
            }
        } while (next_permutation(p + 1, p + 5));
        puts("oo");
        return 0;
    }

    if (n == 5) {
        sort(p + 1, p + 6);
        do {
            if (parallelogram()) {
                point v5, v6, v7, v8;
                v5 = p[5] - p[1];
                v6 = p[4] - p[5];
                v7 = p[5] - p[2];
                v8 = p[3] - p[5];
                if (v5 == v6 && v7 == v8) {
                    printf("5\n");
                    return 0;
                }
            }
        } while (next_permutation(p + 1, p + 6));
        puts("oo");
        return 0;
    }

    return 0;
}
