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

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
double a[maxn], res;

int cmp(double aa, double bb) {
    if (fabs(aa - bb) < EPS)
        return 0;

    if (aa - bb > 0.0)
        return 1;

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    cin >> n;
    cout << fixed << setprecision(15);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1.0) {
            cout << 1.0 << endl;
            return 0;
        }
    }

    sort(a, a + n);
    reverse(a, a + n);

    double sum = 0;
    double neg = 1.0;
    double total = 0;
    for (int i = 0; i < n; i++) {
        total = total * (1.0 - a[i]) + a[i] * neg;
        neg *= 1.0 - a[i];
        if (cmp(total, res) > 0) {
            res = total;
        }
    }

    cout << res << endl;
    return 0;
}
