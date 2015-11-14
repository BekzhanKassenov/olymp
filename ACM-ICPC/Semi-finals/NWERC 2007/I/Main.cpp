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
const int MAXN = 55;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int h, l;
int cars[MAXN][MAXN];

int solveFloor(int i) {
    int ans = 0;
    int pos = 0;
    while (true) {
        int mn = -1;
        for (int j = 0; j < l; j++) {
            if (cars[i][j] != -1 && (mn == -1 || cars[i][mn] > cars[i][j])) {
                mn = j;
            }
        }

        if (mn == -1) {
            break;
        }

        ans += min(abs(mn - pos), l - abs(mn - pos));
        pos = mn;
        cars[i][pos] = -1;
    }

    return ans * 5;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);
    
    while (T--) {
        scanf("%d%d", &h, &l);

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                scanf("%d", &cars[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                if (cars[i][j] != -1) {
                    ans += i * 20;
                }
            }
        }

        for (int i = 0; i < h; i++) {
            ans += solveFloor(i);
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
