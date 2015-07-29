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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
double dist[MAXN][2 * MAXN];
double prob[MAXN][2 * MAXN];
double expected[MAXN][2 * MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * i; j++) {
                int x;
                scanf("%d", &x);
                dist[i][j] = x;
            }
        }

        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                prob[i][j] = 0;
                expected[i][j] = 0;
            }
        }

        prob[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                double dist1 = dist[i][2 * j - 1];
                double dist2 = dist[i][2 * j];

                double addend1 = expected[i][j] + prob[i][j] * dist1;
                double addend2 = expected[i][j] + prob[i][j] * dist2;

                if (dist1 < dist2) {
                    // left
                    prob[i + 1][j] += prob[i][j];
                    expected[i + 1][j] += addend1;
                } else if (dist1 > dist2) {
                    // right
                    prob[i + 1][j + 1] += prob[i][j];
                    expected[i + 1][j + 1] += addend2;
                } else {
                    //bith
                    prob[i + 1][j] += 0.5 * prob[i][j];
                    expected[i + 1][j] += 0.5 * addend1;

                    prob[i + 1][j + 1] += 0.5 * prob[i][j];
                    expected[i + 1][j + 1] += 0.5 * addend2;
                }
            }
        }

        double ans = 0;
        for (int j = 1; j <= n + 1; j++) {
            ans += expected[n + 1][j];
        }

        printf("%.10lf\n", ans);
    }
    
    return 0;
}
