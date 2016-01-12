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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
int x[MAXN], y[MAXN];
map <long long, int> Map;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    int c = 0;
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            Map.clear();

            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                long long dist = sqr(1ll * x[i] - x[j]) + sqr(1ll * y[i] - y[j]);
                Map[dist]++;
            }

            for (auto it: Map) {
                ans += it.second * (it.second - 1) / 2;
            }

        }

        printf("Case #%d: %lld\n", c++, ans);
    }
    
    return 0;
}
