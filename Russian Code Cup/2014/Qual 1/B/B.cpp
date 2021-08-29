/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 1e18;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

ll x, y, k, t, T;

ll jumps(ll x, ll y, ll k, ll t) {
    ll hops = min(t, k);
    x += hops * y;
    t -= hops;
    x += t;
    return x;
}

ll solve1(ll x, ll y, ll k, ll t) {
    ll a = (y - x % y) % y;
    if (a > t) {
        return 0;
    }
    t -= a;
    x += a;
    return jumps(x, y, k, t);
}

ll solve2(ll x, ll y, ll k, ll t) {
    if (x % y == 0) {
        return 0;
    }
    x += (y - x % y) % y;
    k--;
    return jumps(x, y, k, t);
}

ll solve() {
    ll ans1 = x + t;
    ll ans2 = solve1(x, y, k, t);
    ll ans3 = solve2(x, y, k, t);
    /*
    cout << "ans1 " << ans1 << endl;
    cout << "ans2 " << ans2 << endl;
    cout << "ans3 " << ans3 << endl;
    */
    return max(ans1, max(ans2, ans3));
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%lld%lld%lld%lld", &x, &y, &k, &t);

        printf("%lld\n", solve());
    }

    return 0;
}
