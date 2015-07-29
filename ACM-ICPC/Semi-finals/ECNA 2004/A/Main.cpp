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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
long long dp[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    

    for (gets(s + 1); strcmp(s + 1, "0") != 0; gets(s + 1)) {
        dp[1] = 1;
        dp[0] = 1;

        for (int i = 2; s[i]; i++) {
            dp[i] = 0;

            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }

            if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        printf("%I64d\n", dp[strlen(s + 1)]);
    }
    
    return 0;
}
