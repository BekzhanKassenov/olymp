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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m;
    
    cin >> n >> m;
    
    if (n - m == 1 || n == m) {
        for (int i = 0; i < m; i++)
            cout << "01";

        if (n - m == 1) 
            cout << 0;
        return 0;
    }
    
    if (n > m) {
        cout << -1;
        return 0;
    }
    
    int cnt = m - n - 1;
    
    if (cnt - n > 1) {
        cout << -1;
        return 0;
    }
    
    while (n > 0 || m > 0) {
        if (cnt) {
            m -= 2;
            cout << "11";
            cnt--;
        } else if (m) {
            m--;
            cout << 1;
        }
        
        if (n) {
            cout << 0;
            n--;
        }
    }
    
    return 0;
}
