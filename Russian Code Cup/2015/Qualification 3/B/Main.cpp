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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int root(long long n) {
    if (n < 10) {
        return n;
    }

    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return root(sum);
}

int T;
long long a, b;
int cnt[10];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%I64d%I64d", &a, &b);
        memset(cnt, 0, sizeof cnt);

        while (a <= b && root(a) != 1) {
            cnt[root(a)]++;
            a++;
        }

        if (a <= b) {
            do {
                cnt[root(b)]++;

                if (root(b) == 1) {
                    break;
                }

                b--;
            } while (a <= b);
        }

        int mx = 0;
        int cntmx = 0;

        for (int i = 0; i < 10; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
            }
        }

        for (int i = 0; i < 10; i++) {
            if (cnt[i] == mx) {
                cntmx++;
            }
        }

        printf("%d ", cntmx);

        for (int i = 0; i < 10; i++) {
            if (cnt[i] == mx) {
                printf("%d ", i);
            }
        }

        puts("");
    }
    
    return 0;
}
