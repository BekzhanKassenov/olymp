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
const int BSIZE = 5;//256;
const int MAXN = BSIZE * BSIZE;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
    srand(time(NULL));

    int n = rand() % 99 + 1;
    int k = rand() % 10 + 1;

    cout << n << ' ' << k << endl;

    for (int i = 0; i < n; i++) {
        cout << rand() % 20 << ' ';
    }

    cout << endl;

    for (int i = 0; i < k; i++) {
        int l = rand() % n;
        int r = l + rand() % (n - l);
        cout << l + 1 << ' ' << r + 1 << endl;
    }
    
    return 0;
}
