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

template <size_t N>
struct Matrix {
    int a[N][N];

    Matrix() {
        memset(a, 0, sizeof a);
    }
};

template <size_t N>
Matrix <N> operator * (const Matrix <N>& lhs, const Matrix <N>& rhs) {
    Matrix <N> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result.a[i][j] += (1ll * lhs.a[i][k] * rhs.a[k][j]) % MOD;
                result.a[i][j] %= MOD;
            }
        }
    }

    return result;
}

template <size_t N>
Matrix <N> binpower(Matrix <N> base, size_t power) {
    Matrix <N> result;

    for (int i = 0; i < N; i++) {
        result.a[i][i] = 1;
    }

    while (power > 0) {
        if (power & 1) {
            result = result * base;
        }

        base = base * base;
        power >>= 1;
    }

    return result;
}

int dp[MAXN], temp;
int n, x, cnt[MAXN];
int vec[MAXN];
int ans, sum;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &x);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        cnt[temp]++;
    }

    dp[0] = 1;
    sum = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += (1ll * dp[i - j] * cnt[j]) % MOD;
            dp[i] %= MOD;
        }       

        if (i < 101) {
            sum += dp[i];
            sum %= MOD;
        }
    }

    vec[100] = sum;
    for (int i = 0; i < 100; i++) {
        vec[i] = dp[i + 1];
    }

    if (x < MAXN) {
        sum = 0;
        for (int i = 0; i <= x; i++) {
            sum += dp[i];
            sum %= MOD;
        }

        printf("%d\n", sum);
        return 0;
    }

    Matrix <101> B;
    
    for (int i = 0; i < 100; i++) {
        B.a[i][100] = cnt[100 - i];
        B.a[i][99] = cnt[100 - i];
    }

    B.a[100][100] = 1;
    for (int i = 1; i < 100; i++) {
        B.a[i][i - 1] = 1;
    }

    B = binpower(B, x - 100);

    for (int i = 0; i < 101; i++) {
        ans += (1ll * vec[i] * B.a[i][100]) % MOD;
        ans %= MOD;
    }

    printf("%d\n", ans);

    return 0;
}
