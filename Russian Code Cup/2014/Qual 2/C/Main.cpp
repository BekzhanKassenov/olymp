/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <ll> ans;
int T, n, m, x, y;

void solve(ll a, ll b) {
    if (a == 0 || b == 0)
        return;

    ll mn = min(a, b);
    ll mx = max(a, b);

    ll sum = mn * (mn - 1) / 2;

    if (sum > 0)
        ans.push_back(sum);

    sum += (mx - mn) * mn;

    if (sum > 0)
        ans.push_back(sum);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T --> 0) {
        scanf("%d%d%d%d", &n, &m, &x, &y);

        solve(x - 1, y - 1);
        solve(n - x, y - 1);
        solve(x - 1, m - y);
        solve(n - x, m - y);

        sort(all(ans));

        printf("%u ", ans.size());

        for (size_t i = 0; i < ans.size(); i++)
            printf("%I64d ", ans[i]);

        puts("");
        ans.clear();
    }

    return 0;
}
