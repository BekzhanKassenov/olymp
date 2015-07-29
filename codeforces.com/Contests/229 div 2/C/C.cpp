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

const int maxn = 100010;

vector <int> candy[10];
int n, k, w, l, r;
int sum[maxn];
char c;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    cin >> n >> k >> w;
    
    for (int i = 1; i <= n; i++) {
        cin >> c;
        
        if (c == '1') {
            candy[i % k].push_back(i);
            sum[i] = 1;
        }
        
        sum[i] += sum[i - 1]; 
    }
    
    for (int i = 0; i < w; i++) {
        cin >> l >> r;
        
        int cnt = sum[r] - sum[l - 1];
        
        int _left  = lower_bound(all(candy[r % k]), l) - candy[r % k].begin();
        int _right = upper_bound(all(candy[r % k]), r) - candy[r % k].begin() - 1;
        
    //    cout << _left << ' ' << _right << ' ' << _right - _left + 1 << ' ' << cnt << endl;
        
        int ans = cnt - (_right - _left + 1) + (r - l + 1) / k - (_right - _left + 1);
        
        cout << ans << endl;
    }

    return 0;
}
