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

int n, k, d, pos;
vector <int> ans[1010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &d);

    if (k > n) {
        for (int j = 0; j < d; j++) {
            for (int i = 0; i < n; i++)
                printf("%d ", i + 1);

            puts("");
        }

        return 0;
    }

    if (((n + k - 1) / k) / 2 > d) {
        puts("-1");
        return 0;
    }

    for (int j = 0; j < d; j++) {
        for (int i = 0; i < n; i++) {
            int num = i % k;

            if (i / k < j) {
                num++;
                num %= k;
            }

            printf("%d ", num + 1);
        }
        
        puts("");
    }

    return 0;
}
