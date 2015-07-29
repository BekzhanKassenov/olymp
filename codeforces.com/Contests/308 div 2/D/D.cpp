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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

struct Point {
    int x, y;

    void read() {
        scanf("%d%d", &x, &y);
    }
};

struct Line {
    int a, b, c;

    Line() { }

    Line(const Point& p1, const Point& p2) {
       a = p2.y - p1.y;
       b = p1.x - p2.x;
       c = p2.x * p1.y - p1.x * p2.y;
       normalize();
    }

    void normalize() {
        if (a == 0) {
            if (b < 0) {
                b *= -1;
                c *= -1;
            }
        } else if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }

        int g = gcd(gcd(abs(a), abs(b)), abs(c));

        a /= g;
        b /= g;
        c /= g;
    }

    long long hash() const {
        return (c * 40000ll + b) * 40000 + a;
    }

    bool operator < (const Line& l) const {
        if (a != l.a) {
            return a < l.a;
        }

        if (b != l.b) {
            return b < l.b;
        }

        return c < l.c;
    }
};

long long get(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}

int n;
Point p[MAXN];
vector <long long> num;
vector <int> lines;
int cnt[MAXN * MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }

    if (n <= 2) {
        puts("0");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;    
            }

            Line line(p[i], p[j]);
            num.push_back(line.hash());
        }
    }

    sort(all(num));
    num.resize(unique(all(num)) - num.begin());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            Line line(p[i], p[j]);
            int k = lower_bound(all(num), line.hash()) - num.begin();
            lines.push_back(k);
        }

        sort(all(lines));
        lines.resize(unique(all(lines)) - lines.begin());

        for (size_t j = 0; j < lines.size(); j++) {
            cnt[lines[j]]++;
        }

        lines.clear();
    }

    long long ans = get(n);
    for (int i = 0; i < MAXN * MAXN; i++) {
        if (cnt[i] > 2) {
            ans -= get(cnt[i]);
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
