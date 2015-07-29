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
const int maxn = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k, cnt[maxn];
char s[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d\n", &n, &m, &k);

    for (int i = 0; i < n; i++)
        gets(s[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'L') {
                if (j - i >= 0)
                    cnt[j - i]++;
            } else if (s[i][j] == 'R') {
                if (j + i < m)
                   cnt[j + i]++;
            } else if (s[i][j] == 'U') {
                if (!(i & 1))
                    cnt[j]++;
            } 
        }
    }

    for (int j = 0; j < m; j++)
        printf("%d ", cnt[j]);

    return 0;
}
