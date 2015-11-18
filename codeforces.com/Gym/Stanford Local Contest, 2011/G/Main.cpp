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

int n, m, q;
map <pair <int, int>, int> mn, mx;
int x, y, c;
char s[3];

void clear() {
    mn.clear();
    mx.clear();
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d%d", &n, &m, &q) == 3 && (n != 0 || m != 0 || q != 0)) {
        clear();

        for (int i = 0; i < q; i++) {
            scanf("%d%d%s%d", &x, &y, s, &c);

            if (strcmp(s, "<=") == 0) {
                pair <int, int> p(x, y);
                if (!mn.count(p)) {
                    mn[p] = c;
                } else {
                    mn[p] = min(mn[p], c);
                }

            } else {
                pair <int, int> p(x, y);

                if (!mx.count(p)) {
                    mx[p] = c;
                } else {
                    mx[p] = max(mx[p], c);
                }
            }
        }

        bool ok = true;
        for (const auto& p: mn) {
            if (mx.count(p.first) && p.second < mx[p.first]) {
                ok = false;
            }
        }

        if (ok) {
            puts("Possible");
        } else {
            puts("Impossible");
        }
    }
    
    return 0;
}
