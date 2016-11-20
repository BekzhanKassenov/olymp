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

long long n, k, s, t;
long long c[MAXN], v[MAXN];
long long g[MAXN];
long long sum[MAXN];

void read_dist() {
    g[0] = 0;
    g[k + 1] = s;
    for (int i = 1; i <= k; i++) {
        cin >> g[i];
    }

    sort(g, g + k + 2);
    for (int i = 0; i <= k; i++) {
        g[i] = g[i + 1] - g[i];
    }

    sort(g, g + k + 1);
    sum[0] = g[0];
    for (int i = 1; i <= k; i++)  {
        sum[i] = sum[i - 1] + g[i];
    }
}

long long get_sum(int l, int r) {
    if (r < 0 || l > r) {
        return 0;
    }

    if (l <= 0) {
        return sum[r];
    }

    return sum[r] - sum[l - 1];
}

bool pass(int vol) {
    if (g[k] > vol) {
        return false;
    }

    int pos = -1;
    int l = 0, r = k;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (2 * g[mid] <= vol) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    long long T = get_sum(0, pos);
    if (2 * g[k] > vol) {
        long long cnt = k - pos;
        assert(cnt > 0);
        T += 3 * get_sum(pos + 1, k) - cnt * vol;
    }

    return T <= t;
}

int main() {
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k >> s >> t;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> v[i];
    }

    read_dist();

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (pass(v[i])) {
            if (ans == -1 || c[i] < c[ans]) {
                ans = i;
            }
        }
    }

    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << c[ans] << endl;
    }

    return 0;
}
