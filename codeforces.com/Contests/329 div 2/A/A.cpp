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

int cnt[MAXN][26];
char buf[1010];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(buf);

        for (int j = 0; buf[j]; j++) {
            cnt[i][buf[j] - 'a']++;
        }
    }

    int ans = 0;
    for (int c1 = 0; c1 < 26; c1++) {
        for (int c2 = c1 + 1; c2 < 26; c2++) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                bool ok = true;

                for (int j = 0; j < 26; j++) {
                    if (j != c1 && j != c2 && cnt[i][j] > 0) {
                        ok = false;
                    }
                }

                if (ok) {
                    res += cnt[i][c1] + cnt[i][c2];
                }
            }

            ans = max(ans, res);
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
