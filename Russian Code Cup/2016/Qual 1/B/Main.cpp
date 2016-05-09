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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, h;
int a[MAXN];
int on[MAXN];
int start[MAXN], finish[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &h);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &on[i]);
        }

        start[0] = 1;
        finish[0] = start[0] + a[i] - 1;

        for (int i = 1; i < n; i++) {
            start[i] = finish[i - 1] + 1;
            finish[i] = start[i] + a[i] - 1;
        }

        int ans = 0;
        if (!on[0]) {
            ans = 1;
            on[0] = 1;
        }
    }
    
    return 0;
}
