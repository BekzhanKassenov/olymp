/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

const int n = 5;
int g[n][n], a[n], ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    for (int i = 0; i < n; i++) {
        a[i] = i;
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    }

    do {
        int temp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n - 1; j += 2) {
                temp += g[a[j]][a[j + 1]];
                temp += g[a[j + 1]][a[j]];
            }
        }

        ans = max(ans, temp);
    } while (next_permutation(a, a + n));

    printf("%d\n", ans);

    return 0;
}
