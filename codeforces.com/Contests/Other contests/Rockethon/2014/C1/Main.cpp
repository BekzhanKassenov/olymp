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

int mask, n, k;
int p[20], e[20];
int ans = INF;

int get(int msk) {
    int cnt[n];
    
    for (int i = 0; i < n; i++)
        cnt[i] = p[i];
        
    int res = 0;
    
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (msk & (1 << i)) {
            res += e[i];
            c++;
        } else {
            cnt[i]++;
        }
    } 
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (cnt[i] > c || (cnt[i] == c && !(msk & (1 << i))))
            ans++;
    }
    
    if (ans >= k)
        return -1;
        
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> e[i];
    }
    
    for (mask = 0; mask < (1 << n); mask++) {
        if (get(mask) != -1) {
            ans = min(ans, get(mask));
        }
    }
    
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}
