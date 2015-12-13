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
int pos[MAXN], len[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }

    len[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        len[i] = 1;

        if (pos[i - 1] < pos[i]) {
            len[i] = len[i - 1] + 1;
        }

        ans = max(ans, len[i]);
    }

    printf("%d\n", n - ans);
    
    return 0;
}
