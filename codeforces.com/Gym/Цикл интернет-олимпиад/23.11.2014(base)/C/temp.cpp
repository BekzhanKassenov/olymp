/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "hobby"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Point {
    double x, y;
    int num;

    bool operator < (const Point& p) const {
        if (x != p.x)
            return x < p.x;

        return y < p.y;
    }
};

int n;
Point a[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].num = i + 1;
    }

    sort(a, a + n);

    printf("%d\n", n / 2);
    for (int i = 0; i + 1 < n; i += 2) {
        printf("%d %d\n", a[i].num, a[i + 1].num);
    }   
    
    return 0;
}