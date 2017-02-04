/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "walk"

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

enum EVENT_T {
    OPEN,
    CLOSE
};

int main() {
    freopen(File".in", "r", stdin);

    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        double m;
        scanf("%d%lf", &n, &m);

        vector <tuple <double, EVENT_T, int> > vec;
        for (int i = 0; i < n; i++) {
            double x, y;
            int r;
            scanf("%lf%lf%d", &x, &y, &r);
            y = abs(y);

            if (y + r <= m) {
                double cat = sqrt(sqr(m - r) - sqr(y));
                vec.emplace_back(x - cat, OPEN, r);
                vec.emplace_back(x + cat, CLOSE, r);
            }
        }

        sort(all(vec));

        long long sum = 0;
        long long ans = 0;
        for (const auto& t : vec) {
            EVENT_T type;
            int rad;
            tie(ignore, type, rad) = t;

            if (type == OPEN) {
                sum += rad;
            } else {
                sum -= rad;
            }

            ans = max(ans, sum);
        }

        printf("%lld\n", ans);
    }
    
    return 0;
}
