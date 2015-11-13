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
const int MAXA = 1000100;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int phi[MAXA];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 1; i < MAXA; i++) {
        phi[i] += i;
        
        for (int j = 2 * i; j < MAXA; j += i) {
            phi[j] -= phi[i];
        }
    }

    int ans = 0;
    for (int i = 1; i < sqrt(MAXA); i++) {
        ans += (phi[i] == i - 1);
    }

    cerr << ans << endl;

    return 0;
}
