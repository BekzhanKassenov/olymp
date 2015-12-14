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
const int MAXN = 110;
const int MAXT = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, t, n;
int len[MAXN];
bool mem1[MAXT], mem2[MAXT];
bool *pr, *nx;

bool check() {
    pr = mem1;
    nx = mem2;

    for (int i = 0; i <= t; i++) {
        pr[i] = true;
    }

    for (int i = 0; i < n; i++) {
        memset(nx, false, sizeof(bool) * (t + 1));
        for (int j = 0; j <= t; j++) {
            if (pr[j]) {
                if (j + len[i] <= t) {
                    nx[j + len[i]] = true;
                }

                if (j - len[i] >= 0) {
                    nx[j - len[i]] = true;
                }
            }
        }

        swap(pr, nx);
    }

    for (int i = 0; i <= t; i++) {
        if (pr[i]) {
            return true;
        }
    }

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    bool ok = true;
    while (T--) {
        scanf("%d%d", &t, &n);

        for (int i = 0; i < n; i++) {
            int start, end;
            scanf("%d%d", &start, &end);
            len[i] = end - start;
        }

        ok &= check();
    }

    if (ok) {
        puts("possible");
    } else {
        puts("impossible");
    }
    
    return 0;
}
