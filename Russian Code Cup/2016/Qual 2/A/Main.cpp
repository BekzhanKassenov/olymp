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
int n, q;
bool used[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &q);
        memset(used, false, sizeof(bool) * (n + 2));

        while (q--) {
            char type;
            int num;
            scanf("\n%c\n%d", &type, &num);

            if (type == '-') {
                used[num] = true;
                used[n - num + 1] = true;
            } else {
                int ans = -1;
                int cnt = 0;

                for (int i = 1; i <= n; i++) {
                    if (!used[i]) {
                        cnt++;

                        if (cnt == num) {
                            ans = i;
                            break;
                        }
                    }
                }

                printf("%d\n", ans);
            }
        }
    }
    
    return 0;
}
