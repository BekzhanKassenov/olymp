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
const int MAXN = 20;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int ans;

struct tri {
    int x, y, l, d;
};

struct desc {
    int pos, cur, dir;
};

tri a[101];
bool v[30001];

vector<desc> d;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d%d", &n, &k) == 2) {
        ans = 0;
        memset(v, 0, sizeof v);
        for (int i = 0; i < k; i++) {
            scanf("%d%d%d%d", &a[i].y, &a[i].x, &a[i].l, &a[i].d);
        }

        for (int i = 1; i <= n; i++) {
            bool was = false;
            for (int j = 0; j < k; j++) {
                // SE
                if (a[j].d == 1 && a[j].x == i) {
                    was = true;
                    for (int t = a[j].y; t < a[j].y + a[j].l && t < n; t++) {
                        v[t] |= true;
                    }                        
                }
                // NE
                else if (a[j].d == 2 && a[j].x == i) {
                    was = true;
                    for (int t = a[j].y; t > a[j].y - a[j].l && t >= 0; t++) {
                        v[t] |= true;
                    }
                }
            }
            for (int j = 0; j < k; j++) {
                // NW
                if (a[j].d == 3) {
                }
                // SW
                else if (a[j].d == 0) {
                }
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}                       
