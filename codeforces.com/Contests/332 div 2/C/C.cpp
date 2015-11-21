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

int n;
pair <int, int> a[MAXN];
pair <int, int> sorted[MAXN];
map <pair <int, int>, int> pos;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        sorted[i] = a[i];
    }

    sort(sorted + 1, sorted + 1 + n);

    for (int i = 1; i <= n; i++) {
        pos[sorted[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; ) {
        int dest = max(pos[a[i]], pos[sorted[i]]);

        while (i <= dest) {
            dest = max(dest, max(pos[a[i]], pos[sorted[i]]));
            i++;
        }   

        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
