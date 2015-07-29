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

int cnt[MAXN];
int n, x;
long long ans = 0;
int num = -1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = MAXN - 1; i > 0; i--) {
        if (cnt[i] & 1) {
            if (cnt[i - 1] > 0) {
                cnt[i - 1]++;
            }

            cnt[i]--;
        }

        cnt[i] /= 2;

        if (cnt[i] == 0) {
            continue;
        }

        if (num != -1) {
            ans += 1ll * num * i;
            num = -1;
            cnt[i]--;
        }

        long long area = i;
        area = sqr(area);
        area *= cnt[i] / 2;
        ans += area;

        if (cnt[i] & 1) {
            num = i;
        }
    }

    printf("%I64d\n", ans);
    
    return 0;
}
