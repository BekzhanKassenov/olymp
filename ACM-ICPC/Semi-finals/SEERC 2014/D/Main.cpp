/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

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

int x, y;

bool check(int a) {
    for (int lt = 0; lt <= 1; lt++) {                                                                    
        for (int lb = 0; lb <= 1; lb++) {
            for (int rt = 0; rt <= 1; rt++) {
                for (int rb = 0; rb <= 1; rb++) {
                    int n = x - lt - rt,
                        e = y + rt + rb - 2,
                        w = y + lt + lb - 2,
                        s = x - rb - lb;
                    if (n && n%a == 0 && e && e%a == 0 && w && w%a == 0 && s && s%a == 0) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (cin >> x >> y) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (check(a)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }    

    return 0;
}
