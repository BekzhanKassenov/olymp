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
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int MOD = 1000 * 1000 * 1000 + 7;

int C[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN]
bool calced[MAXN][MAXN][MAXN];

int calc(int N, int minpos, int sum) {
    if (N == 1) {
        return 1;
    }

    if (calced[N][minpos][sum]) {
        return dp[N][minpos][sum];
    }

    int& ans = dp[N][minpos][sum];
    ans = 0;
    calced[N][minpos][sum] = true;

    if (minpos == 1 || minpos == N) {
        for (int pos = 1; pos <= N - 1; pos++) {
            ans += calc(N - 1, pos, sum);
            ans %= MOD;
        }
    }

    int L = minpos - 1;
    int R = N - minpos;

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= R; j++) {
            int nsum = sum - (minpos + j - i);

            if (nsum >= 0) {
                int addend = (1ll * C[N - 1][L] * calc(L, i, nsum));
            }
        }
    }
}

class BearPermutations {
public:
    int countPermutations(int N, int S, int M) {
        MOD = M;

        C[0][0] = 1;
        for (int i = 1; i < MAXN; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans += calc(N, i, S);
            ans %= MOD;
        }

        return ans;
    }
};