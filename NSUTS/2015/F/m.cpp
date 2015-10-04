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

int Q;
long double a, b, c;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> Q;

    while (Q--) {
        cin >> a >> b >> c;

        if (1.0 / a + 1.0 / b + 1.0 / c < 1.0) {
            cout << "YES" << endl;            
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}