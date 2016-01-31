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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, p;
double prob[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &p);

    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int cnt = r / p - (l - 1) / p;
        prob[i] = cnt / (r - l + 1.0);
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        int l = (i - 1 + n) % n;
        int r = (i + 1) % n;

        ans += 2000 * prob[i] + 1000 * prob[l] * (1 - prob[i]) + 1000 * prob[r] * (1 - prob[i]);
    }

    printf("%.10lf\n", ans);

    return 0;
}
