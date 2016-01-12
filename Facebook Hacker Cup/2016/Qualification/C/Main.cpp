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

int T;
int n;
long long P;
long long a[MAXN];
long long sum[MAXN];

int solve(int pos) {
    if (a[pos] > P) {
        return pos;
    }

    int l = pos, r = n;

    int ans = n + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        long long S = sum[mid] - sum[pos - 1];

        if (S > P) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    int _case = 0;
    while (T--) {
        scanf("%d%lld", &n, &P);

        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int pos = solve(i);
            ans += pos - i;
        }

        printf("Case #%d: %lld\n", ++_case, ans);
    }
    
    return 0;
}
