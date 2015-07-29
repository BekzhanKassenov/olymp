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

ll a[100010], b[100010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
        cin >> b[i];
        
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (b[i] == 1 || a[i] + a[i] < b[i]) {
            ans--;
        } else {
            ans += (b[i] >> 1) * ((b[i] >> 1) + (b[i] & 1));
        }
    }
    
    cout << ans;
    
    return 0;
}
