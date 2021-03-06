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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int p[MAXN], k[MAXN], r[MAXN];
int ansp, ansk;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    for (int i = 0; i < n; i++) {
        if (abs(r[i] - p[i]) < abs(r[i] - k[i])) {
            ansp++;
        } else if (abs(r[i] - p[i]) > abs(r[i] - k[i])) {
            ansk++;
        }
    }

    printf("%d %d\n", ansp, ansk);
    
    return 0;
}
