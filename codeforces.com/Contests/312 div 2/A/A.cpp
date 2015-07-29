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
const int MAXN = 200110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans;
pair <int, int> a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    sort(a, a + n + 1);

    int pos = -1;
    
    for (int i = 0; i <= n; i++) {
        if (a[i].first == 0) {
            pos = i;
            break;
        }   
    }

    for (int idir = 0; idir < 2; idir++) {
        int dir = idir;
        int l = pos - 1, r = pos + 1;
        int res = 0;

        while ((dir == 0 && l >= 0) || (dir == 1 && r <= n)) {
            if (dir == 0) {
                res += a[l].second;
                l--;
            } else {
                res += a[r].second;
                r++;
            }

            dir ^= 1;
        }

        ans = max(ans, res);
    }

    printf("%d\n", ans);
    
    return 0;
}
