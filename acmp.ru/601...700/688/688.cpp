#include <iostream>
#include <cstdio>

using namespace std;

inline int sqr(int n) {
    return n * n;
}

struct Point {
    long long x, y;

    long long dist_to(const Point& p) const {
        return sqr(x - p.x) + sqr(y - p.y);
    }
    
    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

Point sus, dog, nor;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    sus.read();
    dog.read();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        nor.read();

        if (sus.dist_to(nor) * 4 <= dog.dist_to(nor)) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    puts("NO");

    return 0;
}