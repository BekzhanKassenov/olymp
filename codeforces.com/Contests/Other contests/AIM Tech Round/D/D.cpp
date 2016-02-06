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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int n;
long long c1, c2;
int a[MAXN], b[MAXN];
long long dp[MAXN][3];

void factorize(int num, vector <int>& d) {
    int k = sqrt(num);
    for (int i = 2; i <= k; i++) {
        if (num % i == 0) {
            d.push_back(i);

            do {
                num /= i;
            } while (num % i == 0);
        }
    }

    if (num > 1) {
        d.push_back(num);
    }
}

void update(long long& a, long long val, long long addend) {
    if (val == -1) {
        return;
    }

    val += addend;

    if (a == -1) {
        a = val;
    } else {
        a = min(a, val);
    }
}

long long solve(int d, int a[]) {
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }

    if (a[0] % d != 0 && a[0] % d != 1 && a[0] % d != d - 1) {
        return -1;
    }

    dp[0][0] = (a[0] % d == 0) ? 0 : c2;

    for (int i = 1; i < n; i++) {
        update(dp[i][1], dp[i - 1][0], c1); // start
        update(dp[i][1], dp[i - 1][1], c1); // continue

        if (a[i] % d == 0 || a[i] % d == 1 || a[i] % d == d - 1) {
            int addend = (a[i] % d == 0) ? 0 : c2;

            update(dp[i][0], dp[i - 1][0], addend); // not started
            update(dp[i][2], dp[i - 1][1], addend); // stop
            update(dp[i][2], dp[i - 1][2], addend); // stopped
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cerr << dp[i][j] << ' ';
        }
        cerr << endl;
    }
    cerr << endl;
    */

    long long ans = -1;
    for (int i = 0; i < 3; i++) {
        update(ans, dp[n - 1][i], 0);
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%I64d%I64d", &n, &c1, &c2);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    reverse(b, b + n);

    vector <int> g;
    for (int i = -1; i <= 1; i++) {
        factorize(a[0] + i, g);
        factorize(a[n - 1] + i, g);
    }

    sort(all(g));
    g.resize(unique(all(g)) - g.begin());

    long long ans = (n - 1) * c1;
    for (int d: g) {
        update(ans, solve(d, a), 0);
        update(ans, solve(d, b), 0);
    }

    printf("%I64d\n", ans);

    return 0;
}
