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

int arr[maxn], n, dp[maxn][maxn];
bool calced[maxn][maxn];
vector <int> a;

int solve(int l, int r) {
    if (l > r || calced[l][r])
        return dp[l][r];
        
    calced[l][r] = true;
    
    int& ans = dp[l][r];
    
    if (l == r) {
        ans = 1;
    } else {
        ans = INF;
        
        if (a[l] == a[r])
            ans = solve(l + 1, r - 1) + 1;
            
        ans = min(ans, min(solve(l + 1, r), solve(l, r - 1)) + 1);
        
        for (int i = l + 1; i < r - 1; i++) {
            if (a[i - 1] == a[i + 1]) {
                int temp = min(solve(l, i - 1) + solve(i + 2, r), solve(l, i - 2) + solve(i + 1, r));
                ans = min(ans, temp + 1);
            } else {
                int temp = solve(l, i - 1) + solve(i + 1, r);
                ans = min(ans, temp + 1);
            }
        }
    }
    
    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        
    for (int i = 0; i < n; i++) {
        if (a.empty() || a.back() != arr[i])
            a.push_back(arr[i]);
    } 
    
    n = a.size();
    
    printf("%d\n", solve(0, n - 1));
    
    return 0;
}
