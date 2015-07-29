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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, l[5], r[5];
double prob_less[1 << 5][MAXN];
double expected[1 << 5][MAXN];
double ans;

int get_intersection(int a, int b, int aa, int bb) {
    if (b < aa || bb < a) {
        return 0;
    }

    if (a <= aa && aa <= b && b <= bb) {
        return b - aa + 1;
    }

    if (aa <= a && a <= bb && bb <= b) {
        return bb - a + 1;
    }

    if (aa <= a && b <= bb) {
        return b - a + 1;
    }

    if (a <= aa && bb <= b) {
        return bb - aa + 1;
    }

    assert(false);
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }

    int full_mask = (1 << n) - 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int sum = 1; sum < MAXN; sum++) {
            prob_less[mask][sum] = 1;

            for (int i = 0; i < 5; i++) {
                if (mask & (1 << i)) {
                    prob_less[mask][sum] *= get_intersection(0, sum - 1, l[i], r[i]) / (r[i] - l[i] + 1.0);
                }
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int sum = 1; sum < MAXN; sum++) {
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                double prob = sum;
                for (int i = 0; i < 5; i++) {
                    if (submask & (1 << i)) {
                        prob *= get_intersection(sum, sum, l[i], r[i]) / (r[i] - l[i] + 1.0);
                    }
                }
                prob *= prob_less[mask ^ submask][sum];
                expected[mask][sum] += prob;
            }
            expected[mask][sum] += expected[mask][sum - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int sum = 1; sum < MAXN; sum++) {
            int len = get_intersection(sum, sum, l[i], r[i]);
            double prob = len / (r[i] - l[i] + 1.0);
            ans += prob * expected[full_mask ^ (1 << i)][sum - 1];
        }
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        if (mask & (mask - 1)) {
            for (int sum = 1; sum < MAXN; sum++) {
                double prob = 1;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        int len = get_intersection(sum, sum, l[i], r[i]);

                        prob *= len / (r[i] - l[i] + 1.0);
                    }
                }

                prob *= prob_less[full_mask ^ mask][sum];
                ans += prob * sum;
            }
        }
    }

    printf("%.14lf\n", ans);

    return 0;
}
