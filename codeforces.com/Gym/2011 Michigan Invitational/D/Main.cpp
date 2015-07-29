/****************************************
**          Solution by NU #2          **
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
const int MAXN = 50;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, red, ans;
int cas;
int x[MAXN], y[MAXN], c[MAXN];
int xx[MAXN], yy[MAXN];
int lastx, lasty;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d", &n) && n) {
        cas++;
        red = 0;
        ans = -1;
        lastx = 0;
        lasty = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &c[i]);
            if (c[i] == 0)
                red++;

            xx[i] = x[i];
            yy[i] = y[i];
        }

        sort(xx, xx + n);
        sort(yy, yy + n);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = k; l < n; l++) {
                        int cnt = 0;   
                        bool ok = true;
                        
                        for (int q = 0; q < n; q++) {
                            if (xx[i] <= x[q] && x[q] <= xx[j] &&
                                yy[k] <= y[q] && y[q] <= yy[l]) {
                                if (c[q] == 0)
                                    cnt++;
                                else
                                    ok = false;
                            }
                        }

                        if (ok && cnt + cnt == red) {
                            int area = (xx[j] - xx[i]) * (yy[l] - yy[k]);
                            if (ans == -1 || ans > area)
                                ans = area;
                        }
                    }
                }
            }
        }

        printf("Case %d: %d\n", cas, ans);
    }
    
    return 0;
}
