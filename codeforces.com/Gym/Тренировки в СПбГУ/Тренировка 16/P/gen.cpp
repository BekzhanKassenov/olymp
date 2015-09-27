/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "root"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int p[MAXN];

int main() {
    freopen(File".in", "w", stdout);
    
    int n = rand() % 100 + 1;

    cout << n << endl;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    random_shuffle(p + 1, p + 1 + n);

    for (int i = 1; i <= n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;

    return 0;
}
