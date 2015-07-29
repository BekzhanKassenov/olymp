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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, ans;
char s[MAXN][MAXN];
int cnt[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i][j] == 'W' && cnt[i][j] != 1) {
                int diff = 1 - cnt[i][j];

                for (int ii = 0; ii <= i; ii++) {
                    for (int jj = 0; jj <= j; jj++) {
                        cnt[ii][jj] += diff;
                    }
                }

                ans++;
            } else if (s[i][j] == 'B' && cnt[i][j] != -1) {
                int diff = -1 - cnt[i][j];

                for (int ii = 0; ii <= i; ii++) {
                    for (int jj = 0; jj <= j; jj++) {
                        cnt[ii][jj] += diff;
                    }
                }

                ans++;
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
