/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "segmentupdate"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q;
int t[MAXN], a[MAXN];
int type;
int l, r, x;
char res[20 * MAXN];
int respos;

int sum(int pos) {
    int result = 0;
    for (int i = pos; i > 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

void update(int pos, int val) {
    for (int i = pos; i <= n; i |= i + 1) {
        t[i] += val;
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    while (q--) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d%d%d", &l, &r, &x);

            update(l, x);
            update(r + 1, -x);
        } else {
            scanf("%d", &x);
            sprintf(res + respos, "%d\n", a[x] + sum(x));

            while (res[respos]) {
                respos++;
            }
        }
    }

    puts(res);

    return 0;
}
