/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define B first
#define A second
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

int n, r, avg;
long long sum;
pair <int, int> a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &r, &avg);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].A, &a[i].B);
        sum += a[i].A;
    }

    sort(a, a + n);

    long long goal = 1ll * avg * n;
    long long ans = 0;

    for (int i = 0; i < n && sum < goal; i++) {
        long long cnt = min(goal - sum, (long long) r - a[i].A);
        sum += cnt;
        ans += 1ll * a[i].B * cnt;
    }

    printf("%I64d\n", ans);
    
    return 0;
}
