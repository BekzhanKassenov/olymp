/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "war"

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
const int maxn = 510;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int a[maxn], n;
bool calced[maxn][maxn];
int dp[maxn][maxn];

int solve(int l, int r) {
    if (l > r)
        return 0;
        
    if (calced[l][r])
        return dp[l][r];
        
    calced[l][r] = true;
    
    int& ans = dp[l][r];
    
    if (l == r) {
        ans = 1;
    } else {
        ans = solve(l + 1, r) + 1;
        
        for (int i = l; i <= r; i++) {
            if (a[i] == a[l])       
                ans = min(ans, solve(l + 1, i - 1) + 1 + solve(i + 1, r));
        }
    }
    
    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    n = unique(a, a + n) - a;
    
    printf("%d\n", solve(0, n - 1));
    
    return 0;
}
