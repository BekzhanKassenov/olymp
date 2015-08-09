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
#define File "longest"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, a[maxn], dp[maxn], ans;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j]);
        }
        
        dp[i]++;
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    
    return 0;
}