/****************************************
**          Solution by NU #2          **
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

int n, m;
char s[110][110];
int k, x, y;
int mxi, mxj;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);

        for (int j = 0; j < m; j++) {
            if (s[i][j] != '#')
                continue;

            mxi = max(mxi, i);
            mxj = max(mxj, j);
        }
    }

    int a = mxi + 1;
    int b = mxj + 1;

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);

        if (x >= a && y >= b) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    return 0;
}
