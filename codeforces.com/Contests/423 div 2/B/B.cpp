/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n" ,&n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int mxi = -MAXN, mni = MAXN;
    int mxj = -MAXN, mnj = MAXN;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B') {
                mxi = max(mxi, i);
                mni = min(mni, i);

                mxj = max(mxj, j);
                mnj = min(mnj, j);

                cnt++;
            }
        }
    }

    int len = max(mxi - mni + 1, mxj - mnj + 1);

    if (cnt == 0) {
        puts("1");
        return 0;
    }

    if (len > n || len > m) {
        puts("-1");
        return 0;
    }

    printf("%d\n", sqr(len) - cnt);
    
    return 0;
}
    