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
const int MAXN = 210;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, len;
char s[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (scanf("%d\n", &n); n != 0; scanf("%d\n", &n)) {
        gets(s);
        len = strlen(s);

        for (int i = n; i < len; i += 2 * n) {
            reverse(s + i, s + i + n);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < len; j += n) {
                putchar(s[j]);
            }
        }

        putchar('\n');
    }


    return 0;
}
