/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int N, K;
int dp[25][1000010];
int sum[25][1000010];
bool calced[25][1000010];

void calc(int k) {
    if (k == K + 1) {
        dp[k][N] = 1;
    } else {
        calc(k + 1);
        
        for (int pref = 0; pref <= N; pref++) {
            if (N - pref >= pref) {
                dp[k][pref] = sum[k + 1][pref] - sum[k + 1][N - pref + 1];
                dp[k][pref] += MOD;
                dp[k][pref] %= MOD;
            }
        }
    }
    
    sum[k][N] = dp[k][N];
    
    for (int pref = N - 1; pref >= 0; pref--)
        sum[k][pref] = (sum[k][pref + 1] + dp[k][pref]) % MOD;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> N >> K;
    
    calc(1);
    
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= N; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    
    cout << dp[1][0];
    
    return 0;
}
