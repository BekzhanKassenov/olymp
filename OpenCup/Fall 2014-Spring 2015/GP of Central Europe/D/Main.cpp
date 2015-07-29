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
const int MAXN = 2000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x;
long long cnt[MAXN], ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1; i < MAXN; i++) {
        if (!cnt[i])
            continue;

        ans += cnt[i] * (cnt[i] - 1);
        assert(ans >= 0);

        for (int j = i + i; j < MAXN; j += i) {
            ans += cnt[i] * cnt[j];
            assert(ans >= 0);
        }
    }

    assert(ans >= 0);
    cout << ans << endl;

    return 0;
}
