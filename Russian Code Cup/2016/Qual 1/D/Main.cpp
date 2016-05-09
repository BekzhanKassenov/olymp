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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int t[MAXN];
int cnt[MAXN];
long long ans[MAXN];
vector <int> divs[MAXN];

int sumCnt(int l, int r) {
    if (l >= MAXN) {
        return 0;
    }

    if (l == r) {
        return cnt[r] - (l > 0 ? cnt[l - 1] : 0);
    }

    if (r >= MAXN) {
        r = MAXN - 1;
    }

    if (l - 1 < 0) {
        l = 1;
    }

    return cnt[r] - cnt[l - 1];
}

void add(int idx) {
    int oval = t[idx];
    int nval = t[idx] + 1;

    for (int d: divs[t[idx]]) {
        ans[d] -= (oval + d - 1) / d;
        ans[d] += (nval + d - 1) / d;    
    }

    t[idx] = nval;
}

void sub(int idx) {
    int oval = t[idx];
    int nval = t[idx] - 1;

    for (int d: divs[t[idx] - 1]) {
        ans[d] -= (oval + d - 1) / d;
        ans[d] += (nval + d - 1) / d;    
    }

    t[idx] = nval;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        cnt[t[i]]++;
    }

    for (int i = 1; i < MAXN; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int d = 1; d < MAXN; d++) {
        for (int l = 1, r = d; l < MAXN; l += d, r += d) {
            ans[d] += 1ll * sumCnt(l, r) * (r / d);

            if (r < MAXN) {
                divs[r].push_back(d);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int type, x;
        scanf("%d%d", &type, &x);

        switch (type) {
            case 1:
                add(x);
                break;

            case 2:
                sub(x);
                break;

            case 3:
                printf("%lld\n", ans[x]);
                break;
        }
    }
    
    return 0;
}
