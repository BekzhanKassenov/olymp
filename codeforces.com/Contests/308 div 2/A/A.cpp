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

int n, ans;
int a[101][101];
int is, js, ie, je;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        scanf("%d%d%d%d", &is, &js, &ie, &je);
        for (int i = is; i <= ie; i++) {
            for (int j = js; j <= je; j++) {
                a[i][j]++;
            }
        }
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            ans += a[i][j];
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
