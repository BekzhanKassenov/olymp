/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "casino"
#define prev asdasd
#define next asdasdas

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
int n, m, s;

double dp[2][53];
double p[22];
int w[22];
int prev = 0, next = 1;
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        double _p;

        cin >> _p >> w[i];

        p[i] = (_p + 0.0) / s;
    }

    double ans = 0.0;
    
    dp[0][n] = 1.0;
    
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 53; j++) 
            dp[next][j] = 0.0;
        

        for (int k = n; k >= 1; k--) {
            int p_index = 0;
            for (int j = 1; j < m; j++) {
                double _f = p[p_index] * dp[prev][min(n + 1, k + w[p_index])] + (1.0 - p[p_index]) * dp[prev][k - 1];
                double _s = p[j] * dp[prev][min(n + 1, k + w[j])] + (1.0 - p[j]) * dp[prev][k - 1];
                if (_f < _s) {
                    p_index = j;
                }
            }

            dp[next][k - 1] += dp[prev][k - 1] * (1.0 - p[p_index]);
            dp[next][min(n + 1, k + w[p_index])] += p[p_index] * dp[prev][min(n + 1, k + w[p_index])];
        }

        for (int j = 0; j < n + 2; j++) {
            cerr << dp[next][j] << " ";
        }
        cerr << endl;

        ans += dp[next][n + 1];
        
        swap(next, prev);
    }

    printf("%.8lf", ans);
    return 0;
}
