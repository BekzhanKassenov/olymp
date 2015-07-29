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

int n, k, ans;
int a[MAXN];
int sum[MAXN];
multiset <int> r;

int get_sum(int l, int r) {
    return sum[min(n, r)] - sum[max(l - 1, 0)];
}

int get_max(const multiset <int>& S) {
    if (S.empty())
        return 0;

    return *(--S.end());
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }

    if (2 * k >= n) {
        printf("%d\n", get_sum(1, n));
        return 0;
    }

    for (int i = k; i <= n; i++) {
        r.insert(get_sum(i, i + k - 1));
    }

    for (int i = 1; i <= n; i++) {
        //cout << i << ' ' << ans << endl;

        int cur = get_sum(i, i + k - 1);
        
        if (i + k - 1 <= n) {
            int sr = get_sum(i + k - 1, i + 2 * k - 2);
            r.erase(r.find(sr));
        }

        ans = max(ans, cur + get_max(r));
    }

    printf("%d\n", ans);

    return 0;
}
