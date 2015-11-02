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

int n, s, m;
int x;
int cnt[4];

int getSize(int dp) {
    return dp >> 12;
}

int getNum(int dp) {
    return dp & ((1 << 12) - 1);
}

int pack(int size, int num) {
    return (size << 12) | num;
}

void update(int& dp, int pdp, int delta) {
    int nsize = getSize(pdp) + delta;
    int nnum = getNum(pdp);

    if (nsize >= s) {
        nsize = 0;
        nnum++;
    }

    int size = getSize(dp);
    int num = getNum(dp);

    if (num < nnum || (num == nnum && size < nsize)) {
        dp = pack(nsize, nnum);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &s, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    int dp[cnt[1] + 1][cnt[2] + 1][cnt[3] + 1];
    memset(dp, 0, sizeof dp);
    
    for (int i = 0; i <= cnt[1]; i++) {
        for (int j = 0; j <= cnt[2]; j++) {
            for (int k = 0; k <= cnt[3]; k++) {
                if (i > 0) {
                    update(dp[i][j][k], dp[i - 1][j][k], 1);
                }

                if (j > 0) {
                    update(dp[i][j][k], dp[i][j - 1][k], 2);
                }

                if (k > 0) {
                    update(dp[i][j][k], dp[i][j][k - 1], 3);
                }
            }
        }
    }

    printf("%d\n", min(n, getNum(dp[cnt[1]][cnt[2]][cnt[3]])));

    return 0;
}
