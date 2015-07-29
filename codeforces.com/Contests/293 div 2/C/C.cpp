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

int a[MAXN], pos[MAXN];
int n, m, k, x;
long long ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    while (m--) {
        scanf("%d", &x);

        int posx = pos[x];
        
        ans += (posx - 1) / k + 1;

        if (posx != 1) {
            int left = posx - 1;
            swap(a[left], a[posx]);
            pos[a[left]] = left;
            pos[a[posx]] = posx;
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
