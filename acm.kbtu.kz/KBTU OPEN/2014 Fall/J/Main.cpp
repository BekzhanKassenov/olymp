/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "subs"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[503], b[503], pos[2][503], len[2][503];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[j]) {
                pos[0][j] = pos[1][j] = i;
                len[0][j] = len[1][j] = 1;
                break;
            }
        }

    }
    return 0;
}




















