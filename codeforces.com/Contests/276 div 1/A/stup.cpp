/****************************************
**     Solution by Bekzhan Kassenov    **
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
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        long long l, r;
        cin >> l >> r;

        int anspopcount = __builtin_popcountll(l);
        long long ansnum = l;

        for (long long i = l + 1; i <= r; i++) {
            if (anspopcount < __builtin_popcountll(i)) {
                anspopcount = __builtin_popcountll(i);
                ansnum = i;
            }
        }

        cout << ansnum << endl;
    }

    return 0;
}
