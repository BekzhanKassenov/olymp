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
const int ISNF = 2000 * 1000 * 1000;
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int N;
int dp[MAXN][MAXN];
int fact[2 * MAXN];
int rfact[2 * MAXN];
int rev[2 * MAXN];

int C(int n, int k) {
    int num = fact[n];
    int den = rfact[k];
    den = (1ll * den * rfact[n - k]) % MOD;

    num = (1ll * num * den) % MOD;

    return num;
}

int n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    dp[1][1] = 2;

    for (int i = 2; i < MAXN - 1; i++) {
        for (int open = 0; open <= i; open++) {
            dp[i][open] = (1ll * (open + 1) * dp[i - 1][open + 1]) % MOD;
            
            if (open > 0) {
                dp[i][open] += (2ll * dp[i - 1][open - 1]) % MOD;
            }
        }
    }

    /*
    for (int i = 1; i <= 4; i++) {
        for (int open = 0; open <= i; open++) {
            cout << dp[i][open] << ' ';
        }
        cout << endl;
    }
    */

    rev[1] = 1;
    for (int i = 2; i < 2 * MAXN; i++) {
        rev[i] = ((-(MOD / i) * 1ll * rev[MOD % i]) % MOD + MOD) % MOD;
    }

    fact[1] = 1;
    rfact[1] = 1;
    for (int i = 2; i < 2 * MAXN; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
        rfact[i] = (1ll * rfact[i - 1] * rev[i]) % MOD;
    }

    while (scanf("%d", &n) == 1 && n != 0) {
        if (n == 1) {
            puts("2");
            continue;
        }

        int ans = (2 * dp[2 * n][0]) % MOD;

        for (int i = 2; i < n; i++) {
            int left = (2ll * C(2 * (n - 1), 2 * (i - 1)) * dp[2 * i - 2][0]) % MOD;
            int right = dp[2 * (n - i)][0];
            int middle = (2 * n - 1);

            int temp = (1ll * ((1ll * left * right) % MOD) * middle) % MOD;

            ans = (ans + temp) % MOD;
        }

        printf("%d\n", ans);
    }

    return 0;
}
