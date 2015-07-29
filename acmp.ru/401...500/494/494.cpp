#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    Point() { }

    Point(int x, int y) : x(x), y(y) { }

    Point(const Point& p) {
        *this = p;
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
};

struct Line {
    Point s, V;


};

int cnt(const Line& l, int R) {
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
