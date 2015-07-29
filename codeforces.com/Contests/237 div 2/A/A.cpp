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

    int n;
    cin >> n;
    
    char x;
    bool flag = true;
    
    char c1 = 0, c2 = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            
            if (i == j || j == n - i - 1) {
                if (c1 == 0)
                    c1 = x;
                else if (c1 != x)
                    flag = false;
            } else {
                if (c2 == 0)
                    c2 = x;
                else if (c2 != x)
                    flag = false;
            }
        }
    }
    
    if (flag && c1 != c2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
