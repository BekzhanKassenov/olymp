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

class WaterTank {
    bool check(double R, const vector <int>& t, const vector <int>& x, int C) {
        double cur = 0;
        for (size_t i = 0; i < t.size(); i++) {
            double delta = x[i] - R;
            cur += delta * t[i];

            cur = max(cur, 0.0);

            if (cur >= C) {
                return false;
            }
        }

        return true;
    }
public:
    double minOutputRate(vector <int> t, vector <int> x, int C) {
        double l = 0, r = 1e18;
        double ans = 0;

        for (int i = 0; i < 200; i++) {
            double mid = (l + r) / 2;

            if (check(mid, t, x, C)) {
                r = mid;
                ans = mid;
            } else {
                l = mid;
            }
        }

        return ans;
    }
};

int main() {
    WaterTank tank;

    cout.precision(10);
    cout << fixed;
                                              
    cout << tank.minOutputRate({9,3,4,8,1,2,5,7,6}, {123,456,789,1011,1213,1415,1617,1819,2021}, 11);

    return 0;
}
