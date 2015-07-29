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
const int MAXD = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int k[MAXN];
int ans1[MAXD], ans2[MAXD];
int ptr, cur, day;
int q, x;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }

    while (day < MAXD) {
        if (ptr < n) {
            cur += m;

            while (ptr < n && k[ptr] <= cur) {
                cur -= k[ptr];
                ptr++;
            }
        }

        day++;
        ans1[day] = ptr;
        ans2[day] = cur;
    }

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &x);

        printf("%d %d\n", ans1[x], ans2[x]);
    }
    
    return 0;
}
