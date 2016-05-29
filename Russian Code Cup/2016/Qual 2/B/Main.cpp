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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m;
int a[MAXN], b[MAXN];
char s[MAXN + MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        scanf("\n");
        gets(s);

        sort(a, a + n);
        reverse(a, a + n);

        sort(b, b + m);

        int l = 0;
        int ptr = 0;
        int bal = 0;
        int ans = 0;

        for (int i = 0; i < n + m; i++) {
            if (s[i] == '+') {
                bal += a[ptr++];
            } else {
                if (bal < b[l]) {
                    ans++;
                } else {
                    bal -= b[l++];
                }
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
