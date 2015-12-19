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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k, s;
int mindollar = INF, mineuro = INF;

struct Gadget {
    int type;
    long long price;
    int num;

    bool operator < (const Gadget& g) const {
        return price < g.price;
    }
};

Gadget g[MAXN];
int dollar[MAXN], pound[MAXN];

bool check(int mind, int minp, int dayd, int dayp) {
    int mintype = 1;
    if (dayp < dayd) {
        mintype = 2;
    }

    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < m && cnt < k; i++) {
        if (g[i].type == mintype) {
            cnt++;
            sum += g[i].price;
        }
    }

    if (sum <= s && cnt == k) {
        return true;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &m, &k, &s);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &dollar[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &pound[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%I64d", &g[i].type, &g[i].price);
        g[i].num = i + 1;

        if (g[i].type == 1) {
            g[i].price *= mindollar;
        } else {
            g[i].price *= mineuro;
        }
    }

    sort(g, g + m);

    int l = 1, r = n;

    int ans = -1;
    int ansd, anse;
    while (l <= r) {
        int mid = (l + r) / 2;

        int mind = INF, minp = INF;
        int dayd, daye;

        for (int i = 1; i <= mid; i++) {
            if (dollar[i] < mind) {
                mind = dollar[i];
                dayd = i;
            }

            if (pound[i] < minp) {
                minp = pound[i];
                dayp = i;
            }
        }

        if (check(mind, minp, dayd, dayp)) {
            ans = mid;
            ansd = dayd;
            ansp = dayp;

            l = mid - 1;
        } else {
            r = mid + 1;
        }
    }

    return 0;
}
