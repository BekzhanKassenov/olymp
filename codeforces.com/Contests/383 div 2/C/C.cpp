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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
int b[MAXN];
bool used[MAXN];

int len(int v) {
    used[v] = true;
    int ans = 1;
    if (!used[a[v]]) {
        ans += len(a[v]);
    }

    return ans;
}

long long gcd(long long a, long long b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        if (b[i] != i) {
            cout << -1 << endl;
            return 0;
        }
    }

    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            long long l = len(i);
            if (l % 2 == 0) {
                l /= 2;
            }

            ans = lcm(ans, l);
        }
    }

    cout << ans << endl;

    return 0;
}
