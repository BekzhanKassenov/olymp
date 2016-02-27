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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
    srand(time(NULL));

    cout << 200000 << ' ' << 16 << endl;
    for (int i = 1; i <= 200000; i++) {
        cout << ((1 << 16) - 1) - 1 << ' ';
    }
    cout << endl;

    return 0;
}
