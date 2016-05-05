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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int mx = 0, mn = INF;
    for (int start = 0; start < 7; start++) {
        int day = start;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (day % 7 == 5 || day % 7 == 6) {
                cnt++;
            }
            day++;
        }

        mx = max(mx, cnt);
        mn = min(mn, cnt);
    }

    printf("%d %d\n", mn, mx);

    return 0;
}
