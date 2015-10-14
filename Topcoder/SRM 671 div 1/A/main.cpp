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
const int MAXN = 210;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int dp[MAXN][MAXN][MAXN];

class BearCries {
    void add(int& a, int b) {
        a += b;
        a %= MOD;
    }

public:
    int count(string s) {
        int n = s.size();

        if (s[0] == ';') {
            dp[0][1][1] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (s[i] == '_') {
                        if (j - k > 0) {
                            add(dp[i][j][k], (1ll * (j - k) * dp[i - 1][j][k]) % MOD);
                        }

                        add(dp[i][j][k], (1ll * (k + 1) * dp[i - 1][j][k + 1]) % MOD);

                    } else {
                        if (j > 0 && k > 0) {
                            add(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
                        }
                        
                        add(dp[i][j][k], (1ll * (j + 1 - k) * dp[i - 1][j + 1][k]) % MOD);
                    }

                    /*
                    if (dp[i][j][k] > 0)
                    cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
                    */
                }
            }
        }

        return dp[n - 1][0][0];
    }
};

int main() {
    BearCries test;
    cout << test.count(";_;_;_____;") << endl;
    return 0;
}