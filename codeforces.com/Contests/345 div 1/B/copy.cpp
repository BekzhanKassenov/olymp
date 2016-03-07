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

int n, a, b, T;
long long cost[MAXN];
char s[MAXN];

int bin_search(int pos, int ll) {
    int l = ll, r = n - 1;

    long long addend = 0;
    if (pos > 0) {
        sub = cost[pos - 1];
    }

    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        long long t = ;

        cerr << t << ' ' << T << ' ' << ans << endl;

        if (t <= T) {
            ans = mid - pos + 1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d%d\n", &n, &a, &b, &T);
    gets(s);

    strcpy(s + n, s);
    n *= 2;

    cost[0] = 1 + (s[0] == 'w') * b;
    for (int i = 1; i < n; i++) {
        cost[i] = cost[i - 1] + 1 + (s[i] == 'w') * b;
    }   

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = bin_search(i);
        cnt = min(cnt, n / 2);

        cerr << "CNT " << cnt << endl;

        ans = max(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}
