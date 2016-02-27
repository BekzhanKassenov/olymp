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

int n, d;
int a[MAXN];
int dp[1 << 16];

int read() {
    char buf[20];
    gets(buf);

    int mask = 0;
    for (int i = 0; i < d; i++) {
        mask <<= 1;
        mask |= buf[i] - '0';
    }

    return mask;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &d);

    for (int i = 0; i < n; i++) {
        a[i] = read();
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        vector <int> pos;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                pos.push_back(i);
            }
        }

        bool ok = true;
        for (size_t i = 0; i + 1 < pos.size(); i++) {
            if ((a[pos[i]] & a[pos[i + 1]]) != a[pos[i]]) {
                ok = false;
            }
        }
        
        ans += ok;
    }

    printf("%d\n", ans);

    return 0;
}
