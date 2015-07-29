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
const int MAXN = 55;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
long long m;
long long weight[MAXN];
int ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%I64d", &n, &m);

    weight[0] = 1ll << (n - 1);
    for (int i = 1; i <= n; i++) {
        weight[i] = max(weight[i - 1] >> 1, 1ll);
    }

    int l = 1, r = n;
    int num = 1;
    long long cur = 0;

    while (l <= r) {
        //cout << l << ' ' << r << ' ' << cur + weight[num] << endl;
        if (l == r || cur + weight[num] >= m) {
            ans[l] = num;
            l++;
        } else {
            cur += weight[num];
            ans[r] = num;
            r--;
        }

        num++;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}
