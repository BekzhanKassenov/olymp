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

int n, k;
int id[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &id[i]);
    }

    int start = 1, end = 1;
    for (int i = 1; i <= n; i++) {
        if (start <= k && k <= end) {
            printf("%d\n", id[k]);
            return 0;
        }

        k -= (end - start + 1);
        end++;
    }

    return 0;
}
