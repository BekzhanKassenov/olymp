/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "contests"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 10001;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

ll mem[2][maxn];
long long ans, *dp[2], n, A, B, a[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    cin >> n >> A >> B;

    dp[0] = mem[0];
    dp[1] = mem[1];

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[0][i] = 1;
    }

    dp[0][0] = 1;
    dp[1][1] = a[1];

    for (int j = 1; j <= n; ++j){
        memset(dp[1], 0, sizeof (ll) * (n + 1));

        for (int i = j; i <= n; ++i){
            dp[1][i] = dp[1][i - 1] + dp[0][i - 1] * a[i];
            dp[1][i] %= MOD;
        }

        if (j >= A && j <= B) {
            ans += dp[1][n];
            ans %= MOD;
        }

        swap(dp[0], dp[1]);
    }

    cout << ans;
    
    return 0;
}
