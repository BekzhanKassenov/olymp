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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int t[3][3];
ll dp[3][3][50];
bool calced[3][3][40];

ll calc(int i, int j, int n) {
    if (n == 0)
        return 0;
        
    if (calced[i][j][n])
        return dp[i][j][n];
        
    calced[i][j][n] = true;
    
    int k = 1 + 2 - i - j;
    
    dp[i][j][n] = calc(i, k, n - 1) + t[i][j] + calc(k, j, n - 1);
    dp[i][j][n] = min(dp[i][j][n], calc(i, j, n - 1) + t[i][k] + calc(j, i, n - 1) + t[k][j] + calc(i, j, n - 1));
    
    return dp[i][j][n];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> t[i][j];
            
    int n;
    cin >> n;
    
    cout << calc(0, 2, n);
    return 0;
}
