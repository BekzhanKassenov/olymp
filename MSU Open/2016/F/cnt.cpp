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

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    char s[5];
    gets(s);

    int ans = 0;
    for (int i = 0; s[i]; i++) {
        ans += s[i] - 'a';
    }

    cout << ans % 35 + 1 << endl;

    return 0;
}
