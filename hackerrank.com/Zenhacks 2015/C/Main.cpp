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
char p[MAXN], e[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%s%s", p, e);

        int n = strlen(p);
        for (int i = 0; i < n; i++){
            p[i] -= 'a';
            e[i] -= 'a';
        }

        int ans = INF;
        for (int key = 0; key < 26; key++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if ((p[i] + key) % 26 != e[i]) {
                    cur++;
                }
            }

            ans = min(ans, cur);
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
