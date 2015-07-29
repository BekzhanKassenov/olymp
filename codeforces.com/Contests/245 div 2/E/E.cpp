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
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, x, cnt;
vector <int> a;
int dp[1 << 13][25][25], sum[1 << 13], sz[1 << 13];

bool go(int mask, int pos, int cnt) {
    if (pos == (int)a.size())
        return mask == 0 && cnt == 0;

    if (mask & (1 << pos))
        return false;

    int& res = dp[mask][pos][cnt];
    if (res != -1)
        return res;

    res = 0;
    for (int m = mask; m && !res; m = (m - 1) & mask) {
        if (sum[m] < a[pos] && sum[m] + cnt + 1 >= a[pos]) {
            if (sz[m] > 1 || sum[m] < a[pos] + 1)
                res |= go(mask ^ m, pos + 1, cnt - (a[pos] - sum[m] - 1));
        }
    }

    if (cnt + 1 >= a[pos])
        res |= go(mask, pos + 1, cnt - a[pos] + 1);

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1)
            cnt++;
        else if (x == 2) {
            puts("NO");
            return 0;
        } else 
            a.push_back(x);
    }

    if (cnt < (n + 1) / 2) {
        puts("NO");
        return 0;
    }

    if (n == 1 && cnt == 1) {
        puts("YES");
        return 0;
    }

    sort(all(a));
    reverse(all(a));

    memset(dp, 255, sizeof dp);

    for (int mask = 1; mask < (1 << a.size()); mask++) {
        int k = __builtin_ctz(mask);
        sum[mask] = a[k] + sum[mask ^ (1 << k)];
        sz[mask] = __builtin_popcount(mask);
    }

    if (go((1 << (a.size())) - 2, 0, cnt))
        puts("YES");
    else
        puts("NO");

    return 0;
}
