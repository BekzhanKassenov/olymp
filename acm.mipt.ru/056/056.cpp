#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 20;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

double dp[1 << MAXN];
double x[MAXN], y[MAXN];
int n;

double dist(int i, int j) {
    return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) & 1) {
            continue;
        }

        double val = 1e100;

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j)) || i == j) {
                    continue;
                }

                int pmask = mask ^ (1 << i) ^ (1 << j);

                val = min(val, dp[pmask] + dist(i, j));
            }
        }

        dp[mask] = val;
    }

    cout << setprecision(10) << fixed << dp[(1 << n) - 1] << endl;
    
    return 0;
}
