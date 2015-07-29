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
const int maxn = 1010;
const int maxa = 20010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, a[maxn], res_max = INF, res_pos, res_d;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    sort(a, a + n);
    
    for (int d = 0; d < maxa; d++) {
        int pos = a[0];
        
        int mx = -INF, mn = INF;
        
        for (int i = 0; i < n; i++) {
            mx = max(pos - a[i], mx);
            mn = min(pos - a[i], mn);
            pos += d;
        }
        
        
        int delta = -(mx + mn) / 2;
        
        pos = a[0] + delta;
        
        int start = pos;
        mx = -INF, mn = INF;
        
        for (int i = 0; i < n; i++) {
            mx = max(pos - a[i], mx);
            mn = min(pos - a[i], mn);
            pos += d;
        }
        
        if (max(mx, abs(mn)) < res_max) {
            res_max = max(mx, abs(mn));
            res_d = d;
            res_pos = start;
        }
    }
    
    cout << res_max << endl;
    cout << res_pos << ' ' << res_d;
    
    return 0;
}
