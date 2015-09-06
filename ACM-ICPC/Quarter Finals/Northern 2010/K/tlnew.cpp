/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "kitchen"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 18;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int w, l, n;
bool calced[1 << MAXN][MAXN];
double dp[1 << MAXN][MAXN], x[MAXN], y[MAXN];

double dist(double _x1, double _y1, double _x2, double _y2) {
    return sqrt(sqr(_x2 - _x1) + sqr(_y2 - _y1));
}

double ternary(double _x1, double _y1, double _x2, double _y2,
               double lx, double ly, double rx, double ry) {

    for (int i = 0; i < 20; i++) {
        double diffx = (lx - rx) / 3.0;
        double diffy = (ly - ry) / 3.0;

        double f1x = lx + diffx;
        double f1y = ly + diffy;

        double f2x = lx + 2.0 * diffx;
        double f2y = ly + 2.0 * diffy;

        double fl = dist(f1x, f1y, _x1, _y1) + dist(f1x, f1y, _x2, _y2);
        double fr = dist(f2x, f2y, _x1, _y1) + dist(f2x, f2y, _x2, _y2);

        if (fl < fr) {
            rx = f2x;
            ry = f2y;
        } else {
            lx = f1x;
            ly = f1y;
        }
    }

    return dist(lx, ly, _x1, _y1) + dist(lx, ly, _x2, _y2);
}

double calc(double _x1, double _y1, double _x2, double _y2) {
    double r1 = ternary(_x1, _y1, _x2, _y2, 0, min(_y1, _y2), 0, max(_y1, _y2));
    double r2 = ternary(_x1, _y1, _x2, _y2, w, min(_y1, _y2), w, max(_y1, _y2));
    double r3 = ternary(_x1, _y1, _x2, _y2, min(_x1, _x2), 0, max(_x1, _x2), 0);
    double r4 = ternary(_x1, _y1, _x2, _y2, min(_x1, _x2), l, max(_x1, _x2), l);

    /*
    double r1 = dist(_x1, _y1, 0, (_y1 + _y2) / 2.0) + dist(_x2, _y2, 0, (_y1 + _y2) / 2.0); // left
    double r2 = dist(_x1, _y1, w, (_y1 + _y2) / 2.0) + dist(_x2, _y2, w, (_y1 + _y2) / 2.0); // right
    double r3 = dist(_x1, _y1, (_x1 + _x2) / 2.0, 0) + dist(_x2, _y2, (_x1 + _x2) / 2.0, 0); // down
    double r4 = dist(_x1, _y1, (_x1 + _x2) / 2.0, l) + dist(_x2, _y2, (_x1 + _x2) / 2.0, l); // up
    */
    return min(min(r1, r2), min(r3, r4));
}

double escape(double _x, double _y) {
    return min(min(l - _y, _y), min(w - _x, _x));
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> w >> l >> n;

    double xr, yr;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];                       
    }

    cin >> xr >> yr;

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = dist(xr, yr, x[i], y[i]);
        calced[1 << i][i] = true;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!calced[mask][i]) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    double temp = calc(x[i], y[i], x[j], y[j]) + dp[mask][i];

                    if (calced[mask | (1 << j)][j]) {
                        dp[mask | (1 << j)][j] = min (dp[mask | (1 << j)][j], temp);
                    } else {      
                        calced[mask | (1 << j)][j] = true;
                        dp[mask | (1 << j)][j] = temp;
                    }

                    //fprintf(stderr, "%d %d %.3lf --> %d %d %.3lf\n", mask, i, dp[mask][i], mask | (1 << j), j, dp[mask | (1 << j)][j]);
                }
            }
        }
    }
    cout.precision(10);
    cout << fixed;

    double ans = 1e100;
    for (int i = 0; i < n; i++) {
        if (calced[(1 << n) - 1][i]) {
            ans = min (ans, dp[(1 << n) - 1][i] + escape(x[i], y[i]));
        }        
    }


    cout << ans << endl;

    return 0;
}